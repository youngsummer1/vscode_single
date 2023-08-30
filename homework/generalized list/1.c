// 矩阵加法

// 实现三元组表示的两个稀疏矩阵的加法。相关定义如下：

// #define MAXSIZE 100          //假设非零元个数的最大值为100
// typedef struct {
//     int i,j;									//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
//     ElemType e;						//非零元的值
// }Triple;

// typedef struct {
//     Triple data[MAXSIZE];			// 非零元三元组表
//     int    m, n, len;							// 矩阵的行数、列数和非零元个数
// }TSMatrix;
// 在三元组中，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
// 矩阵加法函数的原型为：

// bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ);
// pM, pN, pQ 分别指向三个矩阵，当 pM 和 pN 两个矩阵不可加时，函数返回 false，否则函数返回 true，且 pQ 指向两个矩阵的和。
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100          //假设非零元个数的最大值为100

typedef int ElemType;

typedef struct {
    int i,j;									//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;						//非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];			// 非零元三元组表
    int    m, n, len;							// 矩阵的行数、列数和非零元个数
}TSMatrix;

// bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ){
//     if(pM->m!=pN->m||pM->n!=pN->n) return false;
//     Triple data1,data2;
//     int idx_m,idx_n;
//     pQ->m=pM->m;pQ->n=pM->n;
//     pQ->len=0;
//     for(idx_m=0,idx_n=0;idx_m<pM->len&&idx_n<pM->len;){
//         data1=pM->data[idx_m];
//         data2=pN->data[idx_n];

//         if(data1.i<data2.i){
//             pQ->data[pQ->len++]=data1;
//             idx_m++;
//         }
//         else if(data1.i>data2.i){
//             pQ->data[pQ->len++]=data2;
//             idx_n++;
//         }
//         else{
//             if(data1.j<data2.j){
//             pQ->data[pQ->len++]=data1;
//             idx_m++;
//             }
//             else if(data1.j>data2.j){
//             pQ->data[pQ->len++]=data2;
//             idx_n++;
//             }
//             else{
//                 pQ->data[pQ->len]=data1;
//                 pQ->data[pQ->len].e+=data2.e;
//                 idx_m++;
//                 idx_n++;
//                 if((pQ->data[pQ->len].e)!=0)pQ->len++;
//             }
//         }
    
//     }
//     while(idx_m<pM->len){
//         pQ->data[pQ->len++]=pM->data[idx_m++];
//     }
//     while(idx_n<pN->len){
//         pQ->data[pQ->len++]=pN->data[idx_n++];
        
//     }
//     return true;

// }

// void add(const TSMatrix* p,TSMatrix* slt){
//     int k;
//     Triple data;
//     for(k=0;k<p->len;k++){
//         data=p->data[k];

//     }
// }
// int main(){
//     TSMatrix pM,pN,pQ;

// }

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ){
    if(pM->m!=pN->m||pM->n!=pN->n) return false;
    Triple data1,data2;
    int idx_m,idx_n;
    pQ->m=pM->m;pQ->n=pM->n;
    pQ->len=0;
    for(idx_m=0,idx_n=0;idx_m<pM->len&&idx_n<pN->len;){
        data1=pM->data[idx_m];
        data2=pN->data[idx_n];

        if(data1.i<data2.i){
            pQ->data[pQ->len++]=data1;
            idx_m++;
        }
        else if(data1.i>data2.i){
            pQ->data[pQ->len++]=data2;
            idx_n++;
        }
        else{
            if(data1.j<data2.j){
            pQ->data[pQ->len++]=data1;
            idx_m++;
            }
            else if(data1.j>data2.j){
            pQ->data[pQ->len++]=data2;
            idx_n++;
            }
            else{
                pQ->data[pQ->len]=data1;
                pQ->data[pQ->len].e+=data2.e;
                idx_m++;
                idx_n++;
                if((pQ->data[pQ->len].e)!=0)pQ->len++;
            }
        }
    
    }
    while(idx_m<pM->len){
        pQ->data[pQ->len++]=pM->data[idx_m++];
        
        
    }
    while(idx_n<pN->len){
        pQ->data[pQ->len++]=pN->data[idx_n++];
        
        
    }
    return true;

}