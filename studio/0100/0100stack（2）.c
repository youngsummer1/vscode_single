#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//解决方法二：
//让u变成全局变量或者静态变量（都存在全局区），让它们不会随着子函数的结束而销毁就好
char *Tell(void)
{
    static char u[] = "I LOVE YOU";
    return u;
}

int main()
{
    char *I = NULL;
    I = Tell();
    printf(I);
    return 0;
}