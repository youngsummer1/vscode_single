// 十字链表

// 十字链表相关定义如下：

// typedef int ElemType;

// // 非零元素结点结构
// typedef struct OLNode
// {
//     int row,col;
//     ElemType value;
//     struct OLNode *right,*down;
// }OLNode,*OLink;

// // 十字链表结构
// typedef struct
// {
//     OLink *rowhead,*colhead;
//     int rows,cols,nums;
// }CrossList, *PCrossList;
// 1）实现十字链表的初始化操作：

//  int init_cross_list(PCrossList L, const ElemType *A, int m, int n);
// 其中 L 指向 CrossList 结构，且各成员已被初始化为0；
// A 为 ElemType 类型数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储（即A[0] 为十字链表第1行第1列的元素；
// A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n+1] 为第2行第2个元素）；
// m 表示十字链表的行数，n 表示十字链表的列数。
// init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非 0 元素的个数。

// 2）实现十字链表的删除操作：

//  int del_cross_list(PCrossList L, ElemType k);
// 其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
// del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct OLNode
{
    int row,col;
    ElemType value;
    struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}CrossList, *PCrossList;


// int init_cross_list(PCrossList L, const ElemType *A, int m, int n){
//     L->rows=m,L->cols=n;
//     int num=0;
//     int i,j;
//     OLink p,rowtemp,coltemp;
//     if(!(L->rowhead=(OLink*)malloc((m+1)*sizeof(OLink))))EXIT_FAILURE;
//     if(!(L->colhead=(OLink*)malloc((n+1)*sizeof(OLink))))EXIT_FAILURE;
//     for(i=0;i<m;i++){
//         L->rowhead[i]=NULL;
//     }
//     for(i=0;i<n;i++){
//         L->colhead[i]=NULL;
//     }
    
//     for(i=0;i<m;i++){
//         for(j=0;j<n;j++){
//             if(A[i*n+j]){
//                 num++;
//                 if(!(p=(OLNode*)malloc(sizeof(OLNode))))EXIT_FAILURE;
//                 p->row=i+1,p->col=j+1;
//                 p->value=A[i*n+j];
//                 p->right=NULL,p->down=NULL;
//                 //行
//                 if(L->rowhead[i]==NULL){
//                     L->rowhead[i]=p;
//                     rowtemp=L->rowhead[i];
                
//                 }
//                 else{
//                     rowtemp->right=p;
//                     rowtemp=p;
//                 }
//                 //列
//                 if(L->colhead[j]==NULL){
//                     L->colhead[j]=p;
//                 }
//                 else{
//                     for(coltemp=L->colhead[j];coltemp->down;coltemp=coltemp->down);
//                     coltemp->down=p;
//                 }
//             }
            
//         }
//     }
//     L->nums=num;
//     return num;
// }


//自己写的
//这个初始化的函数可以和抄的删除函数匹配
//注意colhead和rowhead也是从1开始储存
int init_cross_list(PCrossList L, const ElemType *A, int m, int n){
    L->rows=m,L->cols=n;
    int num=0;
    int i,j;
    OLink p,rowtemp,coltemp;
    if(!(L->rowhead=(OLink*)malloc((m+1)*sizeof(OLink))))EXIT_FAILURE;
    if(!(L->colhead=(OLink*)malloc((n+1)*sizeof(OLink))))EXIT_FAILURE;
    for(i=0;i<=m;i++){
        L->rowhead[i]=NULL;
    }
    for(i=0;i<=n;i++){
        L->colhead[i]=NULL;
    }
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(A[i*n+j]){
                num++;
                if(!(p=(OLNode*)malloc(sizeof(OLNode))))EXIT_FAILURE;
                p->row=i+1,p->col=j+1;
                p->value=A[i*n+j];
                p->right=NULL,p->down=NULL;
                //行
                if(L->rowhead[p->row]==NULL){
                    L->rowhead[p->row]=p;
                    rowtemp=L->rowhead[p->row];
                
                }
                else{
                    rowtemp->right=p;
                    rowtemp=p;
                }
                //列
                if(L->colhead[p->col]==NULL){
                    L->colhead[p->col]=p;
                }
                else{
                    for(coltemp=L->colhead[p->col];coltemp->down;coltemp=coltemp->down);
                    coltemp->down=p;
                }
            }
            
        }
    }
    L->nums=num;
    return num;
}



//抄的
// int init_cross_list(PCrossList L, const ElemType* A, int m, int n)
// {
//     int i;
//     OLink q, p;
//     L->rows = m;
//     L->cols = n;
//     L->nums = 0;
//     if (!(L->rowhead = (OLink*)malloc((m+1) * sizeof(OLink))))
//         return 0;
//     if (!(L->colhead = (OLink*)malloc((n+1) * sizeof(OLink))))
//         return 0;
//     for (i = 0; i <= m; i++)
//         L->rowhead[i] = NULL;
//     for (i = 0; i <= n; i++)
//         L->colhead[i] = NULL;
//     for (i = 0; i < m * n; i++) {
//         if (A[i] == 0)
//             ;
//         else {
//             if (!(p = (OLNode*)malloc(sizeof(OLNode))))
//                 return 0;
//            p->col = i%n+1;
//             p->row = (i+1-p->col)/n+1;
//             p->value = A[i];
//             p->right = NULL;
//             L->nums++;
//             p->down = NULL;
//             if (L->rowhead[p->row] == NULL)
//                 L->rowhead[p->row] = p;
//             else {
//                 q = L->rowhead[p->row];
//                 while (q->right != NULL)
//                     q = q->right;
//                 q->right = p;
//             }
//             if (L->colhead[p->col] == NULL)
//                 L->colhead[p->col] = p;
//             else {
//                 q = L->colhead[p->col];
//                 while (q->down != NULL)
//                     q = q->down;
//                 q->down = p;
//             }
//         }
//     }
//     return L->nums;
// }
// int del_cross_list(PCrossList L, ElemType k)
// {
//     int count = 0;
//     for (int i = 0; i < L->rows+1; ++i) {
//         OLink p = L->rowhead[i];
//         while (p) {
//             if (p->value == k) {
//                 OLink q;
//                 for (q = L->rowhead[i]; q != p && q->right != p; q = q->right) {
//                 }
 
//                 if (q == p) {
//                     L->rowhead[i] = p->right;
//                     p = L->rowhead[i];
//                     count++;
//                     continue;
//                 } else {
//                     q->right = p->right;
//                     p = p->right;
//                     count++;
//                     continue;
//                 }
//             }
//             p = p->right;
//         }
//     }
//     for (int i = 0; i < L->cols+1; ++i) {
//         OLink p = L->colhead[i];
//         while (p != NULL) {
//             if (p->value == k) {
//                 OLink q;
//                 for (q = L->colhead[i]; q != p && q->down != p; q = q->down) {
//                 }
//                 if (q == p) {
//                     L->colhead[i] = p->down;
//                     p = L->colhead[i];
//                     free(q);
//                     continue;
//                 } else {
//                     OLink tmp = q->down;
//                     q->down = p->down;
//                     p = p->down;
//                     free(tmp);
//                     continue;
//                 }
//             }
//             p = p->down;
//         }
//     }
//     return count;
// }