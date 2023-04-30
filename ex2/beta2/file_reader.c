#include <assert.h>
#include "file_reader.h"
#include "grep_flags.h"


Reader* init_file_reader() {
    Reader* fr = (Reader*) calloc (1, sizeof(Reader));
    assert(fr);
    fr->bytes_counter = 0;
    fr->line_counter = 0;
    fr->is_reading = false;
    return fr;
}

void free_file_reader(Reader* fr) {
    if (fr->is_reading) {
        close_file(fr);
    }
    free(fr);
    fr = NULL;
}

void open_file(Reader* fr, char* filename) {
    fr->fp = fopen(filename, "r");
    assert(fr->fp);
}

void close_file(Reader* fr) {
    fclose(fr->fp);
    fr->is_reading = false;
}

void move_file_pointer(Reader* fr, long bytes) {
    if (fseek(fr->fp, bytes, SEEK_CUR) != 0) {
        printf("Error in fseek");
        assert(NULL);
    }
}

void goto_previous_line(Reader* fr){
    move_file_pointer(fr, -2);
    while (getc(fr->fp)!='\n') {
        move_file_pointer(fr, -2);
    }
    return;
}

int read_next_line(Reader* fr, char** line_ptr) {
    size_t len = 0;
    if (getline(line_ptr, &len, fr->fp) == -1){
        return -1;
    }
    fr->bytes_counter = fr->bytes_counter + strlen(*line_ptr) + 1;
    fr->line_counter = fr->line_counter + 1;
    return 0;
}

Reader* get_file_reader(char* filename) {
    Reader* fr = init_file_reader();
    open_file(fr, filename);
    fr->is_reading = true;
    return fr;
}
