// 顺序表 数据调整

// 已知顺序表L中的数据元素类型为int。设计算法将其调整为左右两部分，左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数，并要求算法的时间复杂度为O(n),空间复杂度为O（1）。

// 函数原型如下：
// void odd_even(SeqList *L);

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

void odd_even(SeqList *L){
    ElemType* front=&(L->elem[0]),*button=&(L->elem[L->last]);
    ElemType f,b,temp;
    while(front<button){
        f=(*front)%2;
        b=(*button)%2;
        if(f==0){
            if(b==1){
                temp=*front;
                *front=*button;
                *button=temp;
                front++;
            }
            button--;
        }
        else{
            front++;
        }
    }


}