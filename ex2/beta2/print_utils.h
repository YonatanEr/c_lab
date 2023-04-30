#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include "file_reader.h"
#include "grep_flags.h"

void print_line(Flags* flags, char* line, long bytes_counter, long line_counter, char c);

void print_format(Flags* flags, char* line, Reader* fr);

#endif