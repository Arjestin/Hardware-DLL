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
 * File Name:							hwdll.h																									*
 * Last Update:						24/01/2016																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef HWDLL_H_
#define HWDLL_H_

#include <stdbool.h>



/************************************************************************************************************************	*/
/*                                                             Macro Definitions                                                             	*/
/************************************************************************************************************************	*/

/* Flag for committing the Hardware DLL data structure changes to hardware.										*/
#define COMMIT			true
/* Flag for automatically logging the Hardware DLL data structure after each change.								*/
#define AUTO_LOG		true
/* Maximum number of characters in a fixed-length string (including special characters).							*/
#define STR_MAX			256
/* Maximum number of hardware accelerators.																					*/
#define HWA_MAX		1000
/* Maximum number of reconfigurable partitions.																					*/
#define RP_MAX			100
/* Number of reconfigurable partitions <= minimum of CHAR_BIT * sizeof (int) and RP_MAX.					*/
#define RP_LIST_SIZE		16
/* Offset address of the first reconfigurable partition.																			*/
#define RP_OFFSET		0x40000000
/* Address range of each reconfigurable partition.																				*/
#define RP_RANGE		0x1000
/* Offset address of the first I/O parameter in each hardware accelerator.												*/
#define IO_OFFSET		0x18
/* Address range of each I/O parameter.																								*/
#define IO_RANGE			0x08
/* Pathname of the is_partial_bitstream device attribute file.																	*/
#define PR_FILE				"/sys/devices/amba.1/f8007000.devcfg/is_partial_bitstream"
/* Pathname of the xdevcfg device file.																									*/
#define CFG_FILE			"/dev/xdevcfg"
/* Pathname of the system's physical memory device file.																		*/
#define MEM_FILE			"/dev/mem"
/* Pathname of the dump file.																												*/
#define DUMP_FILE		"/sdcard/hwdll/dump"
/* Pathname of the record file.																											*/
#define REC_FILE			"/sdcard/hwdll/record"
/* Pathname of the log file.																													*/
#define LOG_FILE			"/sdcard/hwdll/log"
/* Pathname of the catalog file.																											*/
#define CAT_FILE			"/sdcard/hwdll/catalog"
/* Pathname of the original FPGA configuration file.																				*/
#define ORIG_FILE			"/sdcard/parallella.bit.bin"
/* Pathname of the blank FPGA configuration file.																					*/
#define BLANK_FILE		"/sdcard/hwdll/library/blank/blank.bin"
/* Pathname of the blank reconfigurable modules' library.																		*/
#define BLANK_LIB			"/sdcard/hwdll/library/blank"



/************************************************************************************************************************	*/
/*                                                     Interface Function Prototypes                                                     	*/
/************************************************************************************************************************	*/

/**
 * hwdll_create						Creates the Hardware DLL data structure:
 * 											Reads entries from the catalog file.
 * 											Locates the available reconfigurable modules.
 * 											Allocates data substructures and initializes them with the gathered data.
 *
 * Return value upon success:	0.
 * Return value upon failure:	-1.
 */
int hwdll_create (void);

/**
 * hwdll_destroy						Destroys the Hardware DLL data structure:
 * 											Deallocates data substructures.
 * 											Unloads all of the hardware accelerators from the FPGA.
 */
void hwdll_destroy (void);

/**
 * hwdll_load							Loads a hardware accelerator into a reconfigurable partition.
 * 											The hardware accelerator's identifier is passed as an argument.
 *
 * Return value upon success:	The utilized reconfigurable partition's index.
 * Return value upon failure:	-1.
 */
int hwdll_load (int id);

/**
 * hwdll_unload						Unloads a hardware accelerator from a reconfigurable partition.
 * 											Active hardware accelerators can be unloaded by force.
 * 											The reconfigurable partition's index is passed as an argument.
 */
void hwdll_unload (int idx, bool force);

/**
 * hwdll_load_list						Loads a list of hardware accelerators into reconfigurable partitions.
 * 											A pointer to the list of hardware accelerator identifiers is passed as an input argument.
 * 											A pointer to the list, in which the utilized reconfigurable partition indexes will be stored, is passed as an output argument.
 *
 * Return value upon success:	0.
 * Return value upon failure:	-1.
 */
int hwdll_load_list (const int* id_list, int* idx_list, int list_size);

/**
 * hwdll_unload_list					Unloads a list of hardware accelerators from reconfigurable partitions.
 * 											Active hardware accelerators can be unloaded by force.
 * 											A pointer to the list of reconfigurable partition indexes is passed as an argument.
 */
void hwdll_unload_list (const int* idx_list, int list_size, bool force);

/**
 * hwdll_read							Reads a hardware accelerator's output.
 * 											Clears the hardware accelerator's activity status.
 * 											The reconfigurable partition's index is passed as an argument.
 * 											A pointer to the list, in which the output parameters will be stored, is passed as an output argument.
 * 											The list's size must be the same as the number of output parameters for the hardware accelerator, as stated in the catalog file.
 * 											Unread output parameters are set as zeros in the list, and as "invalid" in the record file entry.
 *
 * Return value upon success:	The number of read output parameters.
 * Return value upon failure:	-1.
 */
int hwdll_read (int idx, int* out_list);

/**
 * hwdll_write							Writes a hardware accelerator's input.
 * 											The reconfigurable partition's index is passed as an argument.
 * 											A pointer to the list of input parameters is passed as an input argument.
 * 											The list's size must be the same as the number of input parameters for the hardware accelerator, as stated in the catalog file.
 *
 * Return value upon success:	The number of written input parameters.
 * Return value upon failure:	-1.
 */
int hwdll_write (int idx, const int* in_list);

/**
 * hwdll_probe						Probes a hardware accelerator for its activity status.
 * 											Clears the hardware accelerator's activity status.
 * 											The reconfigurable partition's index is passed as an argument.
 *
 * Return value if done:			0.
 * Return value if not done:		-1.
 */
int hwdll_probe (int idx);

/**
 * hwdll_log							Writes the Hardware DLL data structure's content to the log file.
 */
void hwdll_log (void);



/************************************************************************************************************************	*/

#endif /* HWDLL_H_ */
