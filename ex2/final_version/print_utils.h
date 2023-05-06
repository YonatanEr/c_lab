#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include "reader_utils.h"
#include "grep_flags.h"


void print_matched_line(Flags* flags, Reader* reader, char* line);

void print_unmatched_line(Flags* flags, Reader* reader, char* line);



#endif