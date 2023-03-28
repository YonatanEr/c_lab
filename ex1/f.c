#include <stdio.h>

// modify this function
void func(char** s)
{
    *s = "Hello World!";
}

int main()
{
    char* s;
    func(&s);
    printf("s = %s\n", s);
    return 0;
}


