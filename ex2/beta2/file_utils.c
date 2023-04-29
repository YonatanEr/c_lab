#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "file_utils.h"

void move_file_pointer(FILE* fp, long bytes) {
    if (fseek(fp, bytes, SEEK_CUR) != 0) {
        printf("Error in fseek");
        assert(NULL);
    }
}

void goto_last_line(FILE* fp){
    move_file_pointer(fp, -2);
    while (getc(fp)!='\n') {
        move_file_pointer(fp, -2);
    }
    return;
}

