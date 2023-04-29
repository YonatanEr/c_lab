#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include<stdio.h>
#include<stdlib.h>

void move_file_pointer(FILE* fp, long bytes);

void goto_last_line(FILE* fp);

#endif