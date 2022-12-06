#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//出错原因：
//这里的给字符串u的空间在在栈（stack）中分配，是由编译器在声明变量的时候自动分配的，在子函数结束后，这块空间会被回收。
//而Tell（）函数返回字符串的本质是返回这个字符串首地址的指针，让I也指向u指向的地址，本意是想在输出I的时候输出那块空间的内容，但由于栈空间已经被回收，其内的内容也不在了，所以最终输出不了东西。
//解决方法一：
//直接把指向要改变的指针的指针（即&I）传入，通过这个指针直接给字符串I赋值，这样字符串I的值就不会随子函数的结束而销毁
void Tell(char **u)
{
    *u = "I LOVE YOU";
}

int main()
{
    char *I = NULL;
    Tell(&I);
    printf(I);
    return 0;
}