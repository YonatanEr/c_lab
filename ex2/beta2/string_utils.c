#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


int get_substring_start_index(char* str, char* sub_str) {
    for (int i=0; i<strlen(str)-strlen(sub_str); i++) {
        if (compare_slice(str, sub_str, i)) {
            return i;
        }
    }
    return -1;
}

bool compare_slice(char* str, char* sub_str, int ind) {
    for (int i=ind; i<strlen(sub_str); i++) {
        if (str[i] != sub_str[i-ind]) {
            return false;
        }
    }
    return true;
}

