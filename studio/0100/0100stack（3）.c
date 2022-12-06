#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* u=NULL;
char *Tell(void)
{
    u = "I LOVE YOU";
    return u;
}

int main()
{
    char *I = NULL;
    I = Tell();
    printf(I);
    return 0;
}