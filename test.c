#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("text.txt", "r");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1){    
        //printf("%lu\t", len);
        //printf("%lu\n", strlen(line));
        printf("LINE1: %s", line);
        fseek(stdin, 0, SEEK_SET);
        getline(&line, &len, stdin);
        printf("LINE2: %s", line);
    }
    fclose(fp);
    free(line);
    return 0;
}
