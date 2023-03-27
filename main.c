#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "IO.h"
#include "IO.c"

int main(){
    int exit = 0;
    while (exit == false){
        exit = master_io();
    }
    return 0;
}
