#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include<assert.h>
//这里引入了一个头文件，是为了来检查malloc是否分配成功
struct BOOK
{
   char* name;
   int number;
};
void func(char** p)
{
    *p = "C primier plus";   
    //0100出现过的问题，编译器自动分配的空间在栈上，会随函数的结束而销毁
    //这里采用指针的指针来解决
}
void del(char* p)
{
    printf("%s\n",p);
    free(p);    //不够，还要将这个指针置空
    p=NULL;
}
 
int main()
{
    struct BOOK s; 
    s.name=NULL;//字符指针记得要初始化
    char* p;
    func(&p);
  
    
    int* p1 = (int*)malloc(40*sizeof(int));
    assert(p1);//检查malloc是否分配成功，以下都是这样
    int i;
    for(i = 0;i < 40;i++)//在帮别人改代码也出现过这种无语的事，i定义在循环中，其生命周期也局限在这个循环中，下面的i不能用，只需要在外面定义i就好      
    {
        *(p1 + i) = 40 - i;   
        //一开始觉得这里有问题，因为明明只申请了10个int也就是40个字节的空间却能储存40*4字节的数字
        //然后又去查了一下malloc超出范围的后果，觉得是因为malloc会有一定的虚拟内存，同时c的malloc并不做超出范围的检查(感觉和之前问过老师的为什么一个数字数组超出范围了还能存的原因差不多，是历史遗留问题)，所以才导致可以存下
        //后面又想想不对劲，现在觉得是因为本来就只是存了指针，一个指针的大小为一个字节，刚好40个，每个指针又分别指向它存的这个数字（和指针数组类似），所以这里应该没问题
        //不对，这里报错了“堆已损坏”（这个会导致后面申请空间的时候报错），应该是超出范围的原因。。。我之前想的应该错了，就是应该给它申请40*4的空间，可以看成是一个数组（另外实验了一下30*4是可以的，所以是有一定虚拟内存的，只不过没那么大）
    }
    //还不够，要将指针置空，避免变成野指针
    // p1=NULL;
    //但因为下面还需要这个p1，所以就放到结尾吧
    int* p2 = (int*)malloc(sizeof(int)*40); //这是直接给p2赋了一个地址，虽然没有报错，但是可能会有风险，还是改成申请内存吧
    assert(p2);
    for(i = 0;i < 40;i++)
    {
        p1[i] = p2[i];        
    }   
    s.name=(char*)malloc(20);
    assert(s.name);
    strcpy(s.name,p);   
    //这里的s.name并没有分配空间，而且我们不能操控一个空指针，所以得给它分配一块空间，才能执行strcpy
    s.number = 99;
    
    p = (char*)malloc(20);   
    assert(p);
    strcpy(p,"C and pointer"); 
    del(p);
    //统一释放
    free(p1);
    free(p2);
    free(s.name);
    p1=NULL;
    p2=NULL;
    s.name=NULL;

    return 0;
}