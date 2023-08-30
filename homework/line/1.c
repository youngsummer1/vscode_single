// 顺序表 删除指定范围

// 设计一个高效的算法，从顺序表L中删除所有值介于x和y之间(包括x和y)的所有元素（假设y>=x），要求时间复杂度为O(n)，空间复杂度为O(1)。

// 函数原型如下：
// void del_x2y(SeqList *L, ElemType x, ElemType y);

// 相关定义如下：
#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

void del_x2y(SeqList *L, ElemType x, ElemType y){
    int i=0,j=0;
    while(i<=L->last){
        if(L->elem[i]<x||L->elem[i]>y){
            L->elem[j]=L->elem[i];
            j++;
        }
        i++;
        if(i>=MAXSIZE){
            break;
        }
    }
    L->last=--j;
}