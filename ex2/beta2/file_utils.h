#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct FileReader {
    FILE* fp;
    long bytes_counter;
    long line_counter;
} Reader;


Reader* init_file_reader();

void free_file_reader(Reader* fr);

void open_file(Reader* fr, char* filename);

void close_file(Reader* fr);

void move_file_pointer(Reader* fr, long bytes);

void goto_previous_line(Reader* fr);

void read_next_line(Reader* fr, char* line);


#endif