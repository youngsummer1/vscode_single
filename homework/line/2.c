// 顺序表 删除重复

// 编写算法，在一非递减的顺序表L中，删除所有值相等的多余元素。要求时间复杂度为O(n)，空间复杂度为O(1)。

// 函数原型如下：
// void del_dupnum(SeqList *L)

// 相关定义如下：
// struct _seqlist{
//     ElemType elem[MAXSIZE];
//     int last;
// };
// typedef struct _seqlist SeqList;
#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

void del_dupnum(SeqList *L){
    int i=1,j=0;
    while(i<=L->last){
        if(L->elem[j]!=L->elem[i]){
            j++;
            L->elem[j]=L->elem[i];
        }
        i++;
    }
    L->last=j;


}