/* DO NOT EDIT THIS FILE
 * - Copyright: Prof. Kevin Andrea, George Mason University.  All Rights Reserved
 * - Date: Aug 2022
 */

#ifndef VM_PROCESS_H
#define VM_PROCESS_H

#include "vm_settings.h"

#define DEFAULT_PRIORITY 128
#define MIN_PRIORITY 1
#define MAX_PRIORITY 255
#define MAX_AGE 5

typedef struct process_data {
  char *cmd; // Pointer to the command portion of tokenize_cmd
  char input_orig[MAX_CMD]; // Original user-input command
  char input_toks[MAX_CMD]; // Tokenized copy of full-command (to support pointers)
  char *argv[MAX_ARGS]; // Pointers to each arg in tokenize_cmd
  int is_low; // 1 If the process is run with low-priority
  int is_critical; // 1 If the process is run with critical permissions
  pid_t pid;
  struct process_data *next;
} process_data_t;

// Prototypes
void create_process(process_data_t *proc);
void free_process(process_data_t *proc);
int process_find(pid_t pid);
int initialize_process_system();
void deallocate_process_system();

#endif