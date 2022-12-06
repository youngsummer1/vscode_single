#define _CRT_SECURE_NO_WARNINGS 、
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// 函数的目的是让B倒着存A中内容
//1.没有引用stdlib.h（malloc的头文件，malloc.h也行）(这个居然是找最久的，直到点malloc时才发现函数原型不对劲)
//2.strlen只计算字符串的内容，最后的\0不包括，所以length=10
//因此给B开辟空间的时候要是length+1，而src指向A的最后一个字符时应该是length-1（要不然复制到\0会导致B的第一个字符就是\0，导致打印不出来）
//3.给B最后加上个\0来终止（要不然会继续往后读乱码直到读到\0）
//（应该就这些了吧....）
int main()
{
    char* A = "I LOVE YOU";
    char* B = NULL;
    int length = strlen(A);

    B = (char*)malloc(length+1);

    char* dest = B;

    char* src = &A[length-1];

    while (length-- != 0)
        *dest++ = *src--;
    *dest = '\0';
    printf("%s", B);
    return 0;
}