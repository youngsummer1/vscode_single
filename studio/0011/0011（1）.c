#include <string.h>
#include <stdio.h>
#include <malloc.h>

//出问题原因:free()之后需要将指针置空
//因为free的作用是将指针变量和它所指的空间的关系斩断（无法通过指针访问那块空间）
//但实际上指针本身保存的地址并没有改变，被释放的那块内存里面保存的值也没有改变
//如果不给指针置空，会使其变成野指针，十分危险
int main()
{
    char *p = (char *)malloc(100);
    strcpy(p, "nihao");
    free(p);    
    p=NULL;      
    if (p != NULL)         
        strcpy(p, "shijie");
    for (int i = 0; i < 6; i++)
        printf("%c", *(p + i));
    printf("\n");
    return 0;
}