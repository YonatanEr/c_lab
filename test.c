#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("text.txt", "r");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1){    
        printf("LINE:\t\t%s", line);
    }
    printf("AFTER1 = _%d_\n", line[0]==0);
    int x = getline(&line, &len, fp);
    printf("x = %d\n",x );
    printf("AFTER2 = _%d_\n", line[0]==0);
    int y = getline(&line, &len, fp);
    printf("y = %d\n",y );
    int z = getline(&line, &len, fp);
    printf("z = %d\n",z );
    fclose(fp);
    free(line);
    line = NULL;
    return 0;
}
