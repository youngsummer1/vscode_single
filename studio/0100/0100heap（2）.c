#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//方案二：
//在Tell中创建临时的指针，为它分配空间，然后返回这个指针
char* Tell()
{
    char* U = (char *)malloc(100);
    if(NULL==U){//检测是否分配成功
        printf("分配失败");
        exit(1);
    }
    memset(U,'\0',100);//清空内存空间
    return U;
}
int main()
{
    char *I = NULL;
    I=Tell();
    strcpy(I, "I LOVE YOU");
    printf(I);
    free(I);//养成好习惯及时free
    I=NULL;
    return 0;
}