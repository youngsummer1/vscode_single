#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//出错原因：
//Tell函数结束后函数销毁了，虽然申请的空间还在（因为malloc是在堆（heap）中申请的，所以不会因为函数的销毁而销毁，要程序员主动用free才行），但I并不指向那块空间
//方案一
//传入I的地址，用二级指针来改变指针
//（另外要做好安全防护× 养成好的习惯√，在申请空间后清除申请空间中的内容，并且malloc和free最好放在一个函数中避免忘记）
void Tell(char **U)
{
    *U = (char *)malloc(100);
    if(NULL==*U){//检测是否分配成功
        printf("分配失败");
        exit(1);
    }
    memset(*U,'\0',100);//清空内存空间
}
int main()
{
    char *I = NULL;
    Tell(&I);
    strcpy(I, "I LOVE YOU");
    printf(I);
    free(I);//养成好习惯及时free
    I=NULL;
    return 0;
}