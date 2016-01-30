/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																																						*
 * 											Bi-Semestrial Student Project (2014 – 2015)												*
 * 											Parallel Systems Laboratory																	*
 * 											Electrical Engineering Department															*
 * 											Technion – Israel Institute of Technology													*
 *																																						*
 * Title:									Hardware DLL																						*
 * Subject:								Real Time Partial Reconfiguration Management of FPGA by OS					*
 *																																						*
 * Author:								Alon Reznik																							*
 * Supervisor:							Oz Shmueli																							*
 *																																						*
 * File Name:							hwdll.c																									*
 * Last Update:						24/01/2016																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "hwdll.h"



/************************************************************************************************************************	*/
/*                                                             Macro Definitions                                                             	*/
/************************************************************************************************************************	*/

/* Number of nanoseconds in a second.																								*/
#define BILLION			1000000000
/* Maximum number of I/O parameters per hardware accelerator.														*/
#define MAX_IO			(RP_RANGE / 4 - 4) / 2

/**
 * ASSERT								Evaluates an expression.
 *
 * If the expression is false:		Returns the given return value.
 */
#define ASSERT(expression, retval)\
	if (!(expression))\
	{\
		return retval;\
	}

/**
 * ALLOCATE							Allocates an array of pointed variables.
 *
 * If the allocation fails:			Returns the given return value.
 */
#define ALLOCATE(ptr, size, retval)\
	malloc (sizeof (*(ptr)) * size);\
	ASSERT (ptr, retval);



/************************************************************************************************************************	*/
/*                                    Data Structures, Enumerated Types, and Type Aliases                                    	*/
/************************************************************************************************************************	*/

typedef FILE* file_t;
typedef char* str_t;
typedef const char* costr_t;
typedef char flstr_t[STR_MAX];
typedef struct stat stat_t;
typedef struct timespec spec_t;

enum flag_t {DUMP = -1, LOG, RECORD};
typedef enum flag_t flag_t;

struct hwa_t							/* Hardware accelerator.																			*/
{
		int id;							/* Identifier.																							*/
		int in_list_size;				/* Number of input parameters.																*/
		int out_list_size;				/* Number of output parameters.															*/
		str_t rm_lib;					/* Pathname of the reconfigurable modules' library.									*/
		int rm_avl;						/* Binary array of the reconfigurable modules' availability.							*/
		int rm_avl_size;				/* Number of available reconfigurable modules.										*/
};
typedef struct hwa_t* hwa_t;
typedef const struct hwa_t* cohwa_t;

struct rp_t								/* Reconfigurable partition.																		*/
{
		int base_addr;				/* Base address.																						*/
		hwa_t load_hwa;				/* Loaded hardware accelerator.																*/
		hwa_t* match_hwa_list;	/* Dynamic list of pointers to matching hardware accelerators.					*/
		int match_hwa_list_size;	/* Size of the dynamic list.																		*/
};
typedef struct rp_t rp_t;
typedef struct rp_t rp_list_t[RP_LIST_SIZE];

struct hwdll_t							/* Hardware DLL.																					*/
{
		rp_list_t rp_list;				/* List of reconfigurable partitions.															*/
		hwa_t hwa_list;				/* Dynamic list of hardware accelerators.													*/
		int hwa_list_size;				/* Size of the dynamic list.																		*/
};
typedef struct hwdll_t hwdll_t;
static hwdll_t hwdll;
static bool init = false;

static spec_t init_elapsed_time;
static spec_t init_cpu_time;



/************************************************************************************************************************	*/
/*                                                     Auxiliary Function Prototypes                                                     	*/
/************************************************************************************************************************	*/

/**
 * str_copy								Allocates and copies a string.
 *
 * Return value upon success:	A duplicate of the given string.
 * Return value upon failure:	NULL.
 */
static str_t str_copy (costr_t str);

/**
 * file_size_get						Gets the size of a file.
 *
 * Return value upon success:	The size of the given file in bytes.
 * Return value upon failure:	-1.
 */
static int file_size_get (costr_t file_path);

/**
 * spacer_write						Writes a header or a footer to the dump, record, and log files.
 */
static void spacer_write (costr_t function);

/**
 * time_write							Writes the time of a dump, a log, or a record occurrence to the given stream.
 */
static void time_write (file_t file, flag_t flag);

/**
 * error_write							Writes a detailed error message to the dump file.
 */
static void error_write (costr_t function, costr_t message, int num_0, int num_1);

/**
 * error_handle_create			Handles errors from the hwdll_create interface function:
 * 											Writes a detailed error message to the dump file.
 * 											If given, destroys the Hardware DLL data structure and closes the catalog file.
 *
 * Return value:						-1.
 */
static int error_handle_create (file_t catalog, costr_t function, costr_t message, int num_0, int num_1);

/**
 * error_handle_load				Handles errors from the hwdll_load and hwdll_load_list interface functions:
 * 											If given, writes a detailed error message to the dump file.
 * 											If given, deallocates the list of sorted reconfigurable partition indexes, the list of sorted hardware accelerator pointers, and the list of hardware accelerator pointers.
 *
 * Return value:						-1.
 */
static int error_handle_load (hwa_t* hwa_list, hwa_t* sort_hwa_list, int* sort_idx_list, costr_t function, costr_t message, int num_0, int num_1);

/**
 * error_handle_unload			Handles errors from the hwdll_destroy, hwdll_unload, and hwdll_unload_list interface functions:
 * 											If given, writes a detailed error message to the dump file.
 * 											If given, deallocates the list of hardware accelerator identifiers.
 */
static void error_handle_unload (int* id_list, costr_t function, costr_t message, int num_0, int num_1);

/**
 * error_handle_commit			Handles errors from the hwdll_commit auxiliary function:
 * 											Writes a detailed error message to the dump file.
 * 											If given, deallocates the character buffer and closes the file descriptors of the xdevcfg device, and the reconfigurable module or the is_partial_bitstream device attribute.
 *
 * Return value:						-1.
 */
static int error_handle_commit (int rm_fd, int cfg_fd, str_t buffer, costr_t function, costr_t message, int num_0, int num_1);

/**
 * error_handle_access			Handles errors from the hwdll_access auxiliary function, and the hwdll_read and hwdll_write interface functions:
 * 											Writes a detailed error message to the dump file.
 * 											If given, unmaps the hardware accelerator's memory and closes the file descriptor of the system's physical memory device.
 *
 * Return value:						-1.
 */
static int error_handle_access (int mem_fd, void* mem, int page_size, costr_t function, costr_t message, int num_0, int num_1);

/**
 * hwdll_select						Selects which one of the hardware accelerator's reconfigurable modules to load.
 * 											Note: Selecting a reconfigurable module = selecting its matching reconfigurable partition.
 *
 * Return value:						The selected reconfigurable partition's index.
 */
static int hwdll_select (cohwa_t load_hwa);

/**
 * hwdll_update						Updates the Hardware DLL data structure with the load or unload information.
 */
static void hwdll_update (hwa_t load_hwa, int idx);

/**
 * hwdll_commit						Commits the create, destroy, load or unload information to hardware.
 * 											The caller function's name is passed as an argument.
 *
 * Return value upon success:	0.
 * Return value upon failure:	-1.
 */
static int hwdll_commit (cohwa_t load_hwa, int idx, costr_t function);

/**
 * hwdll_access						Accesses a hardware accelerator's memory:
 * 											Maps the hardware accelerator's physical memory to the application process's virtual memory.
 * 											Performs the caller function's routine (read, write, or probe).
 * 											Unmaps the memory.
 * 											The caller function's name is passed as an argument.
 *
 * Return value:						The caller function's return value.
 */
static int hwdll_access (int idx, const int* in_list, int* out_list, costr_t function);

/**
 * hwdll_start							Starts a hardware accelerator's execution.
 */
static void hwdll_start (int idx);



/************************************************************************************************************************	*/
/*                                                             Auxiliary Functions                                                             	*/
/************************************************************************************************************************	*/

static str_t str_copy (costr_t str)
{
	ASSERT (str, NULL);
	str_t retval = malloc (strlen (str) + 1);
	return retval ? strcpy (retval, str) : NULL;
}

static int file_size_get (costr_t file_path)
{
	stat_t file_stat;
	return !stat (file_path, &file_stat) ? file_stat.st_size : 0;
}

static void spacer_write (costr_t function)
{
	int i = 0;
	flstr_t file_path_list[3] = {DUMP_FILE, REC_FILE, LOG_FILE};
	file_t file = NULL;
	for (i = 0; i < 3; i++)
	{
		file = fopen (file_path_list[i], "a");
		fprintf (file, "#################################################################################################\n");
		fprintf (file, !strcmp (function, "hwdll_create") ? "#                               Hardware DLL Data Structure START                               #\n" : "#                               Hardware DLL Data Structure FINISH                              #\n");
		fprintf (file, "#################################################################################################\n\n");
		if (!strcmp (function, "hwdll_destroy"))
		{
			fprintf (file, "\n\n");
		}
		fclose (file);
	}
	return;
}

static void time_write (file_t file, flag_t flag)
{
	flstr_t date = "";
	time_t timestamp = time (NULL);
	spec_t elapsed_time, cpu_time;
	switch (flag)
	{
		case DUMP:
			fprintf (file, "DUMP ENTRY:\tThe following error message was dumped");
			break;
		case LOG:
			fprintf (file, "LOG ENTRY:\tThe following Hardware DLL data structure was logged");
			break;
		case RECORD:
			fprintf (file, "RECORD ENTRY:\tThe following event was recorded");
			break;
	}
	if (timestamp != -1)
	{
		strftime (date, STR_MAX, " at %H:%M:%S (%d/%m/%Y)", localtime (&timestamp));
		fprintf (file, date);
	}
	fprintf (file, ":\n");
	if (clock_gettime (CLOCK_MONOTONIC, &elapsed_time) != -1)
	{
		elapsed_time.tv_sec = elapsed_time.tv_sec - init_elapsed_time.tv_sec;
		elapsed_time.tv_nsec = elapsed_time.tv_nsec - init_elapsed_time.tv_nsec;
		if (elapsed_time.tv_nsec < 0)
		{
			elapsed_time.tv_sec -= 1;
			elapsed_time.tv_nsec += BILLION;
		}
		if (flag == RECORD)
		{
			fprintf (file, "\t");
		}
		fprintf (file, "\t\t\tThe elapsed time since the creation of the Hardware DLL data structure: %d.%09d seconds.\n", (int) elapsed_time.tv_sec, (int) elapsed_time.tv_nsec);
	}
	if (clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &cpu_time) != -1)
	{
		cpu_time.tv_sec = cpu_time.tv_sec - init_cpu_time.tv_sec;
		cpu_time.tv_nsec = cpu_time.tv_nsec - init_cpu_time.tv_nsec;
		if (cpu_time.tv_nsec < 0)
		{
			cpu_time.tv_sec -= 1;
			cpu_time.tv_nsec += BILLION;
		}
		if (flag == RECORD)
		{
			fprintf (file, "\t");
		}
		fprintf (file, "\t\t\tThe CPU time since the creation of the Hardware DLL data structure: %d.%09d seconds.\n", (int) cpu_time.tv_sec, (int) cpu_time.tv_nsec);
	}
	return;
}

static void error_write (costr_t function, costr_t message, int num_0, int num_1)
{
	file_t dump = NULL;
	if (!*function == '\0')
	{
		dump = fopen (DUMP_FILE, "a");
		time_write (dump, DUMP);
		fprintf (dump, "\t\t\tFailed interface function: %s. ", function);
		fprintf (dump, message, num_0, num_1);
		fclose (dump);
	}
	return;
}

static int error_handle_create (file_t catalog, costr_t function, costr_t message, int num_0, int num_1)
{
	error_write (function, message, num_0, num_1);
	hwdll_destroy ();
	if (catalog)
	{
		fclose (catalog);
	}
	return -1;
}

static int error_handle_load (hwa_t* hwa_list, hwa_t* sort_hwa_list, int* sort_idx_list, costr_t function, costr_t message, int num_0, int num_1)
{
	error_write (function, message, num_0, num_1);
	if (sort_idx_list)
	{
		free (sort_idx_list);
		sort_idx_list = NULL;
	}
	if (sort_hwa_list)
	{
		free (sort_hwa_list);
		sort_hwa_list = NULL;
	}
	if (hwa_list)
	{
		free (hwa_list);
		hwa_list = NULL;
	}
	return -1;
}

static void error_handle_unload (int* id_list, costr_t function, costr_t message, int num_0, int num_1)
{
	error_write (function, message, num_0, num_1);
	if (id_list)
	{
		free (id_list);
		id_list = NULL;
	}
	return;
}

static int error_handle_commit (int rm_fd, int cfg_fd, str_t buffer, costr_t function, costr_t message, int num_0, int num_1)
{
	error_write (function, message, num_0, num_1);
	if (buffer)
	{
		free (buffer);
		buffer = NULL;
	}
	if (cfg_fd > -1)
	{
		close (cfg_fd);
	}
	if (rm_fd > -1)
	{
		close (rm_fd);
	}
	return -1;
}

static int error_handle_access (int mem_fd, void* mem, int page_size, costr_t function, costr_t message, int num_0, int num_1)
{
	error_write (function, message, num_0, num_1);
	if (page_size > 0)
	{
		munmap (mem, page_size);
	}
	if (mem_fd > -1)
	{
		close (mem_fd);
	}
	return -1;
}

static int hwdll_select (cohwa_t load_hwa)
{
	int i = 0, j = 0;
	int min_prev = -1, min_curr = -1;
	int idx = -1;
	bool match = false;
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		if (load_hwa->rm_avl & (1 << i))
		{
			min_curr = hwdll.rp_list[i].match_hwa_list[0]->rm_avl_size;
			for (j = 1; j < hwdll.rp_list[i].match_hwa_list_size; j++)
			{
				if (hwdll.rp_list[i].match_hwa_list[j]->rm_avl_size < min_curr)
				{
					min_curr = hwdll.rp_list[i].match_hwa_list[j]->rm_avl_size;
				}
			}
			if (!match)
			{
				idx = i;
				min_prev = min_curr;
				match = true;
			}
			else
			{
				if ((min_curr > min_prev) || (min_curr == min_prev && hwdll.rp_list[i].match_hwa_list_size < hwdll.rp_list[idx].match_hwa_list_size))
				{
					idx = i;
					min_prev = min_curr;
				}
			}
		}
	}
	return idx;
}

static void hwdll_update (hwa_t load_hwa, int idx)
{
	int i = 0;
	hwdll.rp_list[idx].load_hwa = load_hwa;
	for (i = 0; i < hwdll.rp_list[idx].match_hwa_list_size; i++)
	{
		hwdll.rp_list[idx].match_hwa_list[i]->rm_avl ^= (1 << idx);
		load_hwa ? hwdll.rp_list[idx].match_hwa_list[i]->rm_avl_size-- : hwdll.rp_list[idx].match_hwa_list[i]->rm_avl_size++;
	}
	return;
}

static int hwdll_commit (cohwa_t load_hwa, int idx, costr_t function)
{
	int pr_fd = -1, rm_fd = -1, cfg_fd = -1;
	int buffer_size = 0;
	int msg_param = load_hwa ? load_hwa->id : idx;
	flstr_t rm_path = "";
	str_t rm_lib = load_hwa ? load_hwa->rm_lib : BLANK_LIB;
	str_t buffer = NULL;
	pr_fd = open (PR_FILE, O_WRONLY);
	ASSERT (pr_fd > -1, error_handle_commit (-1, -1, NULL, function, "Failed to open the pathname of the is_partial_bitstream device attribute file.\n\n", -1, -1));
	ASSERT (idx == -1 ? write (pr_fd, "0\n", 2) == 2 : write (pr_fd, "1\n", 2) == 2, error_handle_commit (pr_fd, -1, NULL, function, "Failed to set the is_partial_bitstream device attribute file.\n\n", -1, -1));
	close (pr_fd);
	if (idx == -1)
	{
		snprintf (rm_path, STR_MAX, !strcmp (function, "hwdll_create") ? BLANK_FILE : ORIG_FILE);
	}
	else
	{
		snprintf (rm_path, STR_MAX, "%s/rm_%d.bin", rm_lib, idx);
		if (access (rm_path, R_OK))
		{
			snprintf (rm_path, STR_MAX, "%s/rm_0%d.bin", rm_lib, idx);
		}
	}
	rm_fd = open (rm_path, O_RDONLY);
	if (idx == -1)
	{
		ASSERT (rm_fd > -1, error_handle_commit (-1, -1, NULL, function, !strcmp (function, "hwdll_create") ? "Failed to open the pathname of the blank FPGA configuration file.\n\n" : "Failed to open the pathname of the original FPGA configuration file.\n\n", -1, -1));
	}
	else
	{
		ASSERT (rm_fd > -1, error_handle_commit (-1, -1, NULL, function, load_hwa ? "Failed to open the pathname of hardware accelerator %03d reconfigurable module %02d.\n\n" : "Failed to open the pathname of blank reconfigurable module %02d.\n\n", msg_param, idx));
	}
	cfg_fd = open (CFG_FILE, O_WRONLY);
	ASSERT (cfg_fd > -1, error_handle_commit (rm_fd, -1, NULL, function, "Failed to open the pathname of the xdevcfg device file.\n\n", -1, -1));
	buffer_size = file_size_get (rm_path);
	if (idx == -1)
	{
		ASSERT (buffer_size > 0, error_handle_commit (rm_fd, cfg_fd, NULL, function, !strcmp (function, "hwdll_create") ? "Failed to get the size of the blank FPGA configuration file.\n\n" : "Failed to get the size of the original FPGA configuration file.\n\n", -1, -1));
	}
	else
	{
		ASSERT (buffer_size > 0, error_handle_commit (rm_fd, cfg_fd, NULL, function, load_hwa ? "Failed to get the size of hardware accelerator %03d reconfigurable module %02d.\n\n" : "Failed to get the size of blank reconfigurable module %02d.\n\n", msg_param, idx));
	}
	buffer = ALLOCATE (buffer, buffer_size, error_handle_commit (rm_fd, cfg_fd, NULL, function, "Failed to allocate a buffer of %d characters.\n\n", buffer_size, -1));
	if (idx == -1)
	{
		ASSERT (read (rm_fd, buffer, buffer_size) == buffer_size, error_handle_commit (rm_fd, cfg_fd, buffer, function, !strcmp (function, "hwdll_create") ? "Failed to read the content of the blank FPGA configuration file.\n\n" : "Failed to read the content of the original FPGA configuration file.\n\n", -1, -1));
		ASSERT (write (cfg_fd, buffer, buffer_size) == buffer_size, error_handle_commit (rm_fd, cfg_fd, buffer, function, !strcmp (function, "hwdll_create") ? "Failed to write the content of the blank FPGA configuration file to the xdevcfg device file.\n\n" : "Failed to write the content of the original FPGA configuration file to the xdevcfg device file.\n\n", -1, -1));
	}
	else
	{
		ASSERT (read (rm_fd, buffer, buffer_size) == buffer_size, error_handle_commit (rm_fd, cfg_fd, buffer, function, load_hwa ? "Failed to read the content of hardware accelerator %03d reconfigurable module %02d.\n\n" : "Failed to read the content of blank reconfigurable module %02d.\n\n", msg_param, idx));
		ASSERT (write (cfg_fd, buffer, buffer_size) == buffer_size, error_handle_commit (rm_fd, cfg_fd, buffer, function, load_hwa ? "Failed to write the content of hardware accelerator %03d reconfigurable module %02d to the xdevcfg device file.\n\n" : "Failed to write the content of blank reconfigurable module %02d to the xdevcfg device file.\n\n", msg_param, idx));
	}
	free (buffer);
	buffer = NULL;
	close (cfg_fd);
	close (rm_fd);
	return 0;
}

static int hwdll_access (int idx, const int* in_list, int* out_list, costr_t function)
{
	ASSERT (COMMIT, error_handle_access (-1, NULL, 0, __FUNCTION__, "Hardware DLL data structure is not committed to hardware.\n\n", -1, -1));
	ASSERT (idx > -1 && idx < RP_LIST_SIZE, error_handle_access (-1, NULL, 0, function, "Invalid reconfigurable partition index.\n\n", -1, -1));
	ASSERT (hwdll.rp_list[idx].load_hwa, error_handle_access (-1, NULL, 0, function, "Reconfigurable partition %02d is blank.\n\n", idx, -1));
	int i = 0;
	int mem_fd = -1;
	int page_size = 0, page_addr = 0, page_offset = 0;
	int retval = 0;
	void* mem = MAP_FAILED;
	flstr_t parse_list = "";
	file_t record = NULL;
	mem_fd = !strcmp (function, "hwdll_probe") ? open (MEM_FILE, O_RDONLY) : open (MEM_FILE, O_RDWR);
	ASSERT (mem_fd > -1, error_handle_access (-1, NULL, 0, function, "Failed to open the pathname of the system's physical memory device file.\n\n", -1, -1));
	page_size = sysconf (_SC_PAGESIZE);
	ASSERT (page_size > 0, error_handle_access (mem_fd, NULL, 0, function, "Failed to get the system's page size.\n\n", -1, -1));
	page_addr = (hwdll.rp_list[idx].base_addr & (~(page_size - 1)));
	page_offset = hwdll.rp_list[idx].base_addr - page_addr;
	mem = !strcmp (function, "hwdll_probe") ? mmap (NULL, page_size, PROT_READ, MAP_SHARED, mem_fd, page_addr) : mmap (NULL, page_size, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, page_addr);
	ASSERT (mem != MAP_FAILED, error_handle_access (mem_fd, NULL, 0, function, "Failed to map the memory of hardware accelerator %03d in reconfigurable partition %02d.\n\n", hwdll.rp_list[idx].load_hwa->id, idx));
	if (!strcmp (function, "hwdll_read"))
	{
		while (!(*(volatile int*) (mem + page_offset) & 0x04)) {}
		for (i = 0; i < hwdll.rp_list[idx].load_hwa->out_list_size; i++)
		{
			if (!*(volatile int*) (mem + page_offset + IO_OFFSET + 0x04 + (hwdll.rp_list[idx].load_hwa->in_list_size + i) * IO_RANGE))
			{
				out_list[i] = -1;
				snprintf (parse_list, STR_MAX, i == 0 ? "%sinvalid" : "%s, invalid", parse_list);
			}
			else
			{
				out_list[i] = *(volatile int*) (mem + page_offset + IO_OFFSET + (hwdll.rp_list[idx].load_hwa->in_list_size + i) * IO_RANGE);
				snprintf (parse_list, STR_MAX, i == 0 ? "%s%03d" : "%s, %03d", parse_list, out_list[i]);
				retval++;
			}
		}
	}
	if (!strcmp (function, "hwdll_start") || !strcmp (function, "hwdll_write"))
	{
		if (hwdll.rp_list[idx].load_hwa->in_list_size > 0)
		{
			ASSERT (!(*(volatile int*) (mem + page_offset) & 0x08), error_handle_access (mem_fd, mem, page_size, function, "Hardware accelerator %03d in reconfigurable partition %02d is not ready to receive input.\n\n", hwdll.rp_list[idx].load_hwa->id, idx));
			for (i = 0; i < hwdll.rp_list[idx].load_hwa->in_list_size; i++)
			{
				*(volatile int*) (mem + page_offset + IO_OFFSET + i * IO_RANGE) = in_list[i];
				snprintf (parse_list, STR_MAX, i == 0 ? "%s%03d" : "%s, %03d", parse_list, in_list[i]);
			}
		}
		*(volatile int*) (mem + page_offset) = (*(volatile int*) (mem + page_offset) & 0x80) | 0x01;
		retval = hwdll.rp_list[idx].load_hwa->in_list_size;
	}
	if (!strcmp (function, "hwdll_probe"))
	{
		retval = ((*(volatile int*) (mem + page_offset) & 0x02) >> 1) - 1;
	}
	munmap (mem, page_size);
	close (mem_fd);
	if (strcmp (function, "hwdll_start") && strcmp (function, "hwdll_probe"))
	{
		record = fopen (REC_FILE, "a");
		time_write (record, RECORD);
		fprintf (record, !strcmp (function, "hwdll_read") ? "\t\t\t\tThe output \"%s\" was read from hardware accelerator %03d in reconfigurable partition %02d.\n\n" : "\t\t\t\tThe input \"%s\" was written to hardware accelerator %03d in reconfigurable partition %02d.\n\n", parse_list, hwdll.rp_list[idx].load_hwa->id, idx);
		fclose (record);
	}
	return retval;
}

static void hwdll_start (int idx)
{
	hwdll_access (idx, NULL, NULL, __FUNCTION__);
	return;
}



/************************************************************************************************************************	*/
/*                                                             Interface Functions                                                             	*/
/************************************************************************************************************************	*/

int hwdll_create (void)
{
	ASSERT (RP_LIST_SIZE > 0, error_handle_create (NULL, __FUNCTION__, "The defined number of reconfigurable partitions is invalid.\n\n", -1, -1));
	ASSERT (RP_LIST_SIZE <= fmin (CHAR_BIT * sizeof (int), RP_MAX), error_handle_create (NULL, __FUNCTION__, "The defined number of reconfigurable partitions exceeds the maximum of %d.\n\n", fmin (CHAR_BIT * sizeof (int), RP_MAX), -1));
	int i = 0, j = 0, k = 0;
	flstr_t line = "", rm_x_path = "", rm_xx_path = "";
	str_t parse_line = NULL;
	file_t record = NULL;
	file_t catalog = fopen (CAT_FILE, "r");
	ASSERT (catalog, error_handle_create (NULL, __FUNCTION__, "Failed to open the catalog file.\n\n", -1, -1));
	if (init == false)
	{
		for (i = 0; i < RP_LIST_SIZE; i++)
		{
			hwdll.rp_list[i].base_addr = RP_OFFSET + i * RP_RANGE;
			hwdll.rp_list[i].load_hwa = NULL;
			hwdll.rp_list[i].match_hwa_list = NULL;
			hwdll.rp_list[i].match_hwa_list_size = 0;
		}
		hwdll.hwa_list = NULL;
		hwdll.hwa_list_size = 0;
		init = true;
	}
	while (fgets (line, STR_MAX, catalog))
	{
		if (!feof (catalog))
		{
			ASSERT (strcspn (line, "\n") != strlen (line), error_handle_create (catalog, __FUNCTION__, "At least one line in the catalog file exceeds the maximum of %d characters.\n\n", STR_MAX - 2, -1));
			if (line[0] != '#')
			{
				hwdll.hwa_list_size++;
			}
		}
	}
	ASSERT (hwdll.hwa_list_size, error_handle_create (catalog, __FUNCTION__, "No valid entries found in the catalog file.\n\n", -1, -1));
	hwdll.hwa_list = ALLOCATE (hwdll.hwa_list, hwdll.hwa_list_size, error_handle_create (catalog, __FUNCTION__, "Failed to allocate %d hardware accelerator data structures.\n\n", hwdll.hwa_list_size, -1));
	for (i = 0; i < hwdll.hwa_list_size; i++)
	{
		hwdll.hwa_list[i].id = -1;
		hwdll.hwa_list[i].in_list_size = -1;
		hwdll.hwa_list[i].out_list_size = -1;
		hwdll.hwa_list[i].rm_lib = NULL;
		hwdll.hwa_list[i].rm_avl = 0;
		hwdll.hwa_list[i].rm_avl_size = 0;
	}
	rewind (catalog);
	while (fgets (line, STR_MAX, catalog))
	{
		if (!feof (catalog) && line[0] != '#')
		{
			line[strcspn (line, "\n")] = '\0';
			hwdll.hwa_list[j].id = atoi (line);
			ASSERT (hwdll.hwa_list[j].id > -1 && hwdll.hwa_list[j].id < HWA_MAX, error_handle_create (catalog, __FUNCTION__, "Invalid hardware accelerator identifier in catalog entry line %d.\n\n", j, -1));
			for (i = 0; i < j; i++)
			{
				ASSERT (hwdll.hwa_list[i].id != hwdll.hwa_list[j].id, error_handle_create (catalog, __FUNCTION__, "Duplicate hardware accelerator identifier in catalog entry line %d.\n\n", j, -1));
			}
			parse_line = strchr (line, '|');
			ASSERT (parse_line, error_handle_create (catalog, __FUNCTION__, "Invalid format of catalog entry line %d.\n\n", j, -1));
			parse_line++;
			hwdll.hwa_list[j].in_list_size = atoi (parse_line);
			ASSERT (hwdll.hwa_list[j].in_list_size >= 0 && hwdll.hwa_list[j].in_list_size <= MAX_IO, error_handle_create (catalog, __FUNCTION__, "Invalid number of input parameters for hardware accelerator %03d.\n\n", hwdll.hwa_list[j].id, -1));
			parse_line = strchr (parse_line, '|');
			ASSERT (parse_line, error_handle_create (catalog, __FUNCTION__, "Invalid format of catalog entry line %d.\n\n", j, -1));
			parse_line++;
			hwdll.hwa_list[j].out_list_size = atoi (parse_line);
			ASSERT (hwdll.hwa_list[j].out_list_size >= 0 && hwdll.hwa_list[j].out_list_size <= MAX_IO, error_handle_create (catalog, __FUNCTION__, "Invalid number of output parameters for hardware accelerator %03d.\n\n", hwdll.hwa_list[j].id, -1));
			ASSERT (hwdll.hwa_list[j].in_list_size + hwdll.hwa_list[j].out_list_size <= MAX_IO, error_handle_create (catalog, __FUNCTION__, "The total number of I/O parameters for hardware accelerator %03d exceeds the maximum of %d.\n\n", hwdll.hwa_list[j].id, MAX_IO));
			parse_line = strchr (parse_line, '|');
			ASSERT (parse_line, error_handle_create (catalog, __FUNCTION__, "Invalid format of catalog entry line %d.\n\n", j, -1));
			parse_line += 2;
			ASSERT (strlen (parse_line) + 11 < STR_MAX, error_handle_create (catalog, __FUNCTION__, "The pathname of hardware accelerator %03d exceeds the maximum of %d characters.\n\n", hwdll.hwa_list[j].id, STR_MAX - 2));
			ASSERT (!access (parse_line, R_OK), error_handle_create (catalog, __FUNCTION__, "Failed to access the pathname of hardware accelerator %03d.\n\n", hwdll.hwa_list[j].id, -1));
			for (i = 0; i < RP_LIST_SIZE; i++)
			{
				if (i < 10)
				{
					snprintf (rm_xx_path, STR_MAX, "%s/rm_0%d.bin", parse_line, i);
				}
				snprintf (rm_x_path, STR_MAX, "%s/rm_%d.bin", parse_line, i);
				if ((i < 10 && !access (rm_xx_path, R_OK)) || !access (rm_x_path, R_OK))
				{
					hwdll.hwa_list[j].rm_avl |= (1 << i);
					hwdll.hwa_list[j].rm_avl_size++;
					hwdll.rp_list[i].match_hwa_list_size++;
				}
			}
			ASSERT (hwdll.hwa_list[j].rm_avl_size, error_handle_create (catalog, __FUNCTION__, "The pathname in catalog entry %d has no valid reconfigurable modules.\n\n", j, -1));
			hwdll.hwa_list[j].rm_lib = str_copy (parse_line);
			ASSERT (hwdll.hwa_list[j].rm_lib, error_handle_create (catalog, __FUNCTION__, "Failed to allocate the pathname in catalog entry %d.\n\n", j, -1));
			j++;
		}
	}
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		if (hwdll.rp_list[i].match_hwa_list_size)
		{
			hwdll.rp_list[i].match_hwa_list = ALLOCATE (hwdll.rp_list[i].match_hwa_list, hwdll.rp_list[i].match_hwa_list_size, error_handle_create (catalog, __FUNCTION__, "Failed to allocate a list of %d hardware accelerator pointers.\n\n", hwdll.rp_list[i].match_hwa_list_size, -1));
			k = 0;
			for (j = 0; j < hwdll.hwa_list_size; j++)
			{
				if (hwdll.hwa_list[j].rm_avl & (1 << i))
				{
					hwdll.rp_list[i].match_hwa_list[k] = &hwdll.hwa_list[j];
					k++;
				}
			}
		}
	}
	if (COMMIT)
	{
		ASSERT (!hwdll_commit (NULL, -1, __FUNCTION__), error_handle_create (catalog, "", "", -1, -1));
	}
	if (clock_gettime (CLOCK_MONOTONIC, &init_elapsed_time) == -1)
	{
		init_elapsed_time.tv_sec = 0;
		init_elapsed_time.tv_nsec = 0;
	}
	if (clock_gettime (CLOCK_PROCESS_CPUTIME_ID, &init_cpu_time) == -1)
	{
		init_cpu_time.tv_sec = 0;
		init_cpu_time.tv_nsec = 0;
	}
	fclose (catalog);
	spacer_write (__FUNCTION__);
	record = fopen (REC_FILE, "a");
	time_write (record, RECORD);
	fprintf (record, "\t\t\t\tThe Hardware DLL data structure is created.\n\n");
	fclose (record);
	if (AUTO_LOG)
	{
		hwdll_log ();
	}
	return 0;
}

void hwdll_destroy (void)
{
	int i = 0;
	file_t record = fopen (REC_FILE, "a");
	time_write (record, RECORD);
	fprintf (record, "\t\t\t\tThe Hardware DLL data structure is destroyed.\n\n");
	fclose (record);
	if (COMMIT)
	{
		ASSERT (!hwdll_commit (NULL, -1, __FUNCTION__), error_handle_unload (NULL, "", "", -1, -1));
	}
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		hwdll.rp_list[i].load_hwa = NULL;
		if (hwdll.rp_list[i].match_hwa_list)
		{
			free (hwdll.rp_list[i].match_hwa_list);
			hwdll.rp_list[i].match_hwa_list = NULL;
		}
		hwdll.rp_list[i].match_hwa_list_size = 0;
	}
	if (hwdll.hwa_list)
	{
		for (i = 0; i < hwdll.hwa_list_size; i++)
		{
			if (hwdll.hwa_list[i].rm_lib)
			{
				free (hwdll.hwa_list[i].rm_lib);
				hwdll.hwa_list[i].rm_lib = NULL;
			}
		}
		free (hwdll.hwa_list);
		hwdll.hwa_list = NULL;
	}
	hwdll.hwa_list_size = 0;
	spacer_write (__FUNCTION__);
	return;
}

int hwdll_load (int id)
{
	int i = 0;
	int idx = -1;
	file_t record = NULL;
	while (i < hwdll.hwa_list_size)
	{
		if (hwdll.hwa_list[i].id == id)
		{
			break;
		}
		i++;
	}
	ASSERT (i < hwdll.hwa_list_size, error_handle_load (NULL, NULL, NULL, __FUNCTION__, "Hardware accelerator %03d not found in the Hardware DLL data structure.\n\n", id, -1));
	ASSERT (hwdll.hwa_list[i].rm_avl_size > 0, error_handle_load (NULL, NULL, NULL, __FUNCTION__, "All reconfigurable partitions for hardware accelerator %03d are utilized.\n\n", id, -1));
	idx = hwdll_select (&hwdll.hwa_list[i]);
	hwdll_update (&hwdll.hwa_list[i], idx);
	if (COMMIT)
	{
		ASSERT (!hwdll_commit (&hwdll.hwa_list[i], idx, __FUNCTION__), error_handle_load (NULL, NULL, NULL, "", "", -1, -1));
		if (!hwdll.rp_list[idx].load_hwa->in_list_size)
		{
			hwdll_start (idx);
		}
	}
	record = fopen (REC_FILE, "a");
	time_write (record, RECORD);
	fprintf (record, "\t\t\t\tHardware accelerator %03d is loaded into reconfigurable partition %02d.\n\n", id, idx);
	fclose (record);
	if (AUTO_LOG)
	{
		hwdll_log ();
	}
	return idx;
}

void hwdll_unload (int idx, bool force)
{
	ASSERT (idx > -1 && idx < RP_LIST_SIZE, error_handle_unload (NULL, __FUNCTION__, "Invalid reconfigurable partition index.\n\n", -1, -1));
	ASSERT (hwdll.rp_list[idx].load_hwa, error_handle_unload (NULL, __FUNCTION__, "Reconfigurable partition %02d is already blank.\n\n", idx, -1));
	int load_id = hwdll.rp_list[idx].load_hwa->id;
	file_t record = NULL;
	if (force)
	{
		ASSERT (!hwdll_probe (idx), error_handle_unload (NULL, __FUNCTION__, "Hardware accelerator %03d in reconfigurable partition %02d is active.\n\n", load_id, idx));
	}
	hwdll_update (NULL, idx);
	if (COMMIT)
	{
		ASSERT (!hwdll_commit (NULL, idx, __FUNCTION__), error_handle_unload (NULL, "", "", -1, -1));
	}
	record = fopen (REC_FILE, "a");
	time_write (record, RECORD);
	fprintf (record, "\t\t\t\tHardware accelerator %03d is unloaded from reconfigurable partition %02d.\n\n", load_id, idx);
	fclose (record);
	if (AUTO_LOG)
	{
		hwdll_log ();
	}
	return;
}

int hwdll_load_list (const int* id_list, int* idx_list, int list_size)
{
	ASSERT (id_list, error_handle_load (NULL, NULL, NULL, __FUNCTION__, "Invalid list of hardware accelerator identifiers.\n\n", -1, -1));
	ASSERT (idx_list, error_handle_load (NULL, NULL, NULL, __FUNCTION__, "Invalid placeholder for the list of reconfigurable partition indexes.\n\n", -1, -1));
	ASSERT (list_size >= 1 && list_size <= RP_LIST_SIZE, error_handle_load (NULL, NULL, NULL, __FUNCTION__, "Invalid number of hardware accelerators to load.\n\n", -1, -1));
	int i = 0, j = 0;
	int length = list_size;
	int* sort_idx_list = NULL;
	flstr_t message = "", parse_id_list = "", parse_idx_list = "";
	hwa_t* hwa_list = ALLOCATE (hwa_list, list_size, error_handle_load (NULL, NULL, NULL, __FUNCTION__, "Failed to allocate a list of %d hardware accelerator pointers.\n\n", list_size, -1));
	hwa_t* sort_hwa_list = ALLOCATE (sort_hwa_list, list_size + 1, error_handle_load (hwa_list, NULL, NULL, __FUNCTION__, "Failed to allocate a list of %d hardware accelerator pointers.\n\n", list_size + 1, -1));
	file_t record = NULL;
	sort_hwa_list[list_size] = NULL;
	for (i = 0; i < list_size; i++)
	{
		j = 0;
		while (j < hwdll.hwa_list_size)
		{
			if (hwdll.hwa_list[j].id == id_list[i])
			{
				break;
			}
			j++;
		}
		ASSERT (j < hwdll.hwa_list_size, error_handle_load (hwa_list, sort_hwa_list, NULL, __FUNCTION__, "Hardware accelerator %03d not found in the Hardware DLL data structure.\n\n", id_list[i], -1));
		ASSERT (hwdll.hwa_list[j].rm_avl_size > 0, error_handle_load (hwa_list, sort_hwa_list, NULL, __FUNCTION__, "All reconfigurable partitions for hardware accelerator %03d are utilized.\n\n", id_list[i], -1));
		hwa_list[i] = &hwdll.hwa_list[j];
		sort_hwa_list[i] = &hwdll.hwa_list[j];
		snprintf (parse_id_list, STR_MAX, i == 0 ? "%s%03d" : "%s, %03d", parse_id_list, id_list[i]);
	}
	record = fopen (REC_FILE, "a");
	time_write (record, RECORD);
	fprintf (record, list_size == 1 ? "\t\t\t\tAttempting to load hardware accelerator %s.\n\n" : "\t\t\t\tAttempting to load hardware accelerators %s.\n\n", parse_id_list);
	fclose (record);
	sort_idx_list = ALLOCATE (sort_idx_list, list_size, error_handle_load (hwa_list, sort_hwa_list, NULL, __FUNCTION__, "Failed to allocate a list of %d reconfigurable partition indexes.\n\n", list_size, -1));
	for (i = 0; i < list_size; i++)
	{
		length = list_size - i;
		sort_hwa_list[length] = sort_hwa_list[length - 1];
		for (j = 0; j < length; j++)
		{
			if (sort_hwa_list[j]->rm_avl_size < sort_hwa_list[length]->rm_avl_size)
			{
				sort_hwa_list[length - 1] = sort_hwa_list[length];
				sort_hwa_list[length] = sort_hwa_list[j];
				sort_hwa_list[j] = sort_hwa_list[length - 1];
			}
		}
		sort_idx_list[i] = hwdll_select (sort_hwa_list[length]);
		if (sort_idx_list[i] < 0)
		{
			for (j = 0; j < i; j++)
			{
				hwdll_update (NULL, sort_idx_list[j]);
			}
			snprintf (message, STR_MAX, list_size == 1 ? "Failed to load hardware accelerator %s.\n\n" : "Failed to load hardware accelerators %s.\n\n", parse_id_list);
			ASSERT (NULL, error_handle_load (hwa_list, sort_hwa_list, sort_idx_list, __FUNCTION__, message, -1, -1));
		}
		hwdll_update (sort_hwa_list[length], sort_idx_list[i]);
	}
	for (i = 0; i < list_size; i++)
	{
		for (j = 0; j < list_size; j++)
		{
			if (sort_idx_list[j] >= 0 && hwdll.rp_list[sort_idx_list[j]].load_hwa->id == id_list[i])
			{
				idx_list[i] = sort_idx_list[j];
				sort_idx_list[j] = -1;
				break;
			}
		}
		snprintf (parse_idx_list, STR_MAX, i == 0 ? "%s%02d" : "%s, %02d", parse_idx_list, idx_list[i]);
	}
	if (COMMIT)
	{
		for (i = 0; i < list_size; i++)
		{
			ASSERT (!hwdll_commit (hwa_list[i], idx_list[i], __FUNCTION__), error_handle_load (hwa_list, sort_hwa_list, sort_idx_list, "", "", -1, -1));
			if (!hwdll.rp_list[idx_list[i]].load_hwa->in_list_size)
			{
				hwdll_start (idx_list[i]);
			}
		}
	}
	free (sort_idx_list);
	sort_idx_list = NULL;
	free (sort_hwa_list);
	sort_hwa_list = NULL;
	free (hwa_list);
	hwa_list = NULL;
	record = fopen (REC_FILE, "a");
	time_write (record, RECORD);
	fprintf (record, list_size == 1 ? "\t\t\t\tHardware accelerator %s is loaded into reconfigurable partition %s.\n\n" : "\t\t\t\tHardware accelerators %s are loaded into reconfigurable partitions %s respectively.\n\n", parse_id_list, parse_idx_list);
	fclose (record);
	if (AUTO_LOG)
	{
		hwdll_log ();
	}
	return 0;
}

void hwdll_unload_list (const int* idx_list, int list_size, bool force)
{
	ASSERT (idx_list, error_handle_unload (NULL, __FUNCTION__, "Invalid list of reconfigurable partition indexes.\n\n", -1, -1));
	ASSERT (list_size >= 1 && list_size <= RP_LIST_SIZE, error_handle_unload (NULL, __FUNCTION__, "Invalid number of hardware accelerators to unload.\n\n", -1, -1));
	int i = 0;
	int* id_list = ALLOCATE (id_list, list_size, error_handle_unload (NULL, __FUNCTION__, "Failed to allocate a list of %d hardware accelerator identifiers.\n\n", list_size, -1));
	flstr_t parse_id_list = "", parse_idx_list = "";
	file_t record = NULL;
	for (i = 0; i < list_size; i++)
	{
		ASSERT (idx_list[i] > -1 && idx_list[i] < RP_LIST_SIZE, error_handle_unload (id_list, __FUNCTION__, "Invalid reconfigurable partition index.\n\n", -1, -1));
		ASSERT (hwdll.rp_list[idx_list[i]].load_hwa, error_handle_unload (id_list, __FUNCTION__, "Reconfigurable partition %02d is already blank.\n\n", idx_list[i], -1));
		id_list[i] = hwdll.rp_list[idx_list[i]].load_hwa->id;
		if (force)
		{
			ASSERT (!hwdll_probe (idx_list[i]), error_handle_unload (NULL, __FUNCTION__, "Hardware accelerator %03d in reconfigurable partition %02d is active.\n\n", id_list[i], idx_list[i]));
		}
	}
	for (i = 0; i < list_size; i++)
	{
		hwdll_update (NULL, idx_list[i]);
		if (COMMIT)
		{
			ASSERT (!hwdll_commit (NULL, idx_list[i], __FUNCTION__), error_handle_unload (id_list, "", "", -1, -1));
		}
		snprintf (parse_id_list, STR_MAX, i == 0 ? "%s%03d" : "%s, %03d", parse_id_list, id_list[i]);
		snprintf (parse_idx_list, STR_MAX, i == 0 ? "%s%02d" : "%s, %02d", parse_idx_list, idx_list[i]);
	}
	free (id_list);
	id_list = NULL;
	record = fopen (REC_FILE, "a");
	time_write (record, RECORD);
	fprintf (record, list_size == 1 ? "\t\t\t\tHardware accelerator %s is unloaded from reconfigurable partition %s.\n\n" : "\t\t\t\tHardware accelerators %s are unloaded from reconfigurable partitions %s respectively.\n\n", parse_id_list, parse_idx_list);
	fclose (record);
	if (AUTO_LOG)
	{
		hwdll_log ();
	}
	return;
}

int hwdll_read (int idx, int* out_list)
{
	ASSERT (out_list, error_handle_access (-1, NULL, 0, __FUNCTION__, "Invalid placeholder for the list of output parameters.\n\n", -1, -1));
	return hwdll_access (idx, NULL, out_list, __FUNCTION__);
}

int hwdll_write (int idx, const int* in_list)
{
	ASSERT (in_list, error_handle_access (-1, NULL, 0, __FUNCTION__, "Invalid list of input parameters.\n\n", -1, -1));
	return hwdll_access (idx, in_list, NULL, __FUNCTION__);
}

int hwdll_probe (int idx)
{
	return hwdll_access (idx, NULL, NULL, __FUNCTION__);
}

void hwdll_log (void)
{
	int i = 0, j = 0, k = 0;
	file_t log = fopen (LOG_FILE, "a");
	time_write (log, LOG);
	fprintf (log, "\t\t\tThe number of hardware accelerators in the Hardware DLL data structure: %d.\n", hwdll.hwa_list_size);
	if (hwdll.hwa_list)
	{
		fprintf (log, "\n %s | %s  | %s | %s  | %-*s | %s\n", "ID", "In", "Out", "NA", RP_LIST_SIZE * 3 - 1, "Available Reconfigurable Modules", "Library Pathname");
		fprintf (log, "––––|–––––|–––––|–––––|");
		if (RP_LIST_SIZE < 12)
		{
			fprintf (log, "––––––––––––––––––––––––––––––––––");
		}
		else
		{
			for (i = 0; i < RP_LIST_SIZE * 3 + 1; i++)
			{
				fprintf (log, "–");
			}
		}
		fprintf (log, "|––––––––––––––––––\n");
		for (i = 0; i < hwdll.hwa_list_size; i++)
		{
			fprintf (log, "%03d | ", hwdll.hwa_list[i].id);
			fprintf (log, "%3d | ", hwdll.hwa_list[i].in_list_size);
			fprintf (log, "%3d | ", hwdll.hwa_list[i].out_list_size);
			fprintf (log, "%3d | ", hwdll.hwa_list[i].rm_avl_size);
			for (j = 0; j < RP_LIST_SIZE; j++)
			{
				hwdll.hwa_list[i].rm_avl & (1 << j) ? fprintf (log, "%02d ", j) : fprintf (log, "-- ");
			}
			RP_LIST_SIZE < 11 ? fprintf (log, "%*c %s\n", 34 - (RP_LIST_SIZE * 3), '|', hwdll.hwa_list[i].rm_lib) : fprintf (log, "| %s\n", hwdll.hwa_list[i].rm_lib);
		}
	}
	fprintf (log, "\n#####################################################\n");
	fprintf (log, "# Legend:                                           #\n");
	fprintf (log, "# ID  - Hardware accelerator identifier.            #\n");
	fprintf (log, "# In  - Number of input parameters.                 #\n");
	fprintf (log, "# Out - Number of output parameters.                #\n");
	fprintf (log, "# NA  - Number of available reconfigurable modules. #\n");
	fprintf (log, "#####################################################\n");
	fprintf (log, "\n%s | %s | %s  | %s  | %s\n", "IDX", "Base Address", "ID", "NM", "Matching Hardware Accelerators");
	fprintf (log, "––––|––––––––––––––|–––––|–––––|––––––––––––––––––––––––––––––––\n");
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		fprintf (log, " %02d |", i);
		fprintf (log, "  0x%X  |", hwdll.rp_list[i].base_addr);
		!hwdll.rp_list[i].load_hwa ? fprintf (log, " --- |") : fprintf (log, " %03d |", hwdll.rp_list[i].load_hwa->id);
		fprintf (log, " %3d |", hwdll.rp_list[i].match_hwa_list_size);
		j = 0;
		if (hwdll.rp_list[i].match_hwa_list)
		{
			k = 0;
			while (k < hwdll.rp_list[i].match_hwa_list_size)
			{
				if (hwdll.hwa_list[j].id == hwdll.rp_list[i].match_hwa_list[k]->id)
				{
					fprintf (log, " %03d", hwdll.rp_list[i].match_hwa_list[k]->id);
					k++;
				}
				else
				{
					fprintf (log, " ---");
				}
				j++;
			}
		}
		while (j < hwdll.hwa_list_size)
		{
			fprintf (log, " ---");
			j++;
		}
		fprintf (log, "\n");
	}
	fprintf (log, "\n#####################################################\n");
	fprintf (log, "# Legend:                                           #\n");
	fprintf (log, "# IDX - Reconfigurable partition index.             #\n");
	fprintf (log, "# ID  - Loaded hardware accelerator identifier.     #\n");
	fprintf (log, "# NM  - Number of matching hardware accelerators.   #\n");
	fprintf (log, "#####################################################\n\n");
	fclose (log);
	return;
}



/************************************************************************************************************************	*/
