// 链表 删除范围内结点

// 已知线性表中的元素（整数）以值递增有序排列，并以单链表作存储结构。试写一高效算法，删除表中所有大于mink且小于maxk的元素（若表中存在这样的元素），分析你的算法的时间复杂度。

// 链表结点定义如下：
// struct _lnklist{
//     ElemType data;
//     struct _lnklist *next;
// };
// typedef struct _lnklist Node;
// typedef struct _lnklist *LinkList;
// 函数原型如下：
// void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)

// 其中L指向链表的头结点。
#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

// void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
//     if(!L->next){
//         return;
//     }
//     Node *s,*temp;
//     temp=L->next;
//     while(temp->next){
//         s=temp->next;
//         if(s->data>mink&&s->data<maxk){
//             temp->next=s->next;
//             free(s);
//             continue;
//         }
//         if(temp->next->data>=maxk)break;

//         temp=temp->next;
//     }
// }
void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
    if(!L->next){
        return;
    }
    Node *s,*temp;
    temp=L;
    while(temp->next){
        s=temp->next;
        if(s->data>mink&&s->data<maxk){
            temp->next=s->next;
            free(s);
            continue;
        }
        if(temp->next->data>=maxk)break;

        temp=temp->next;
    }
}
// void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
//     if(!L->next){
//         return;
//     }
//     Node* min=L,*max=L;
//     while(L->next){
//         if(L->next->data>mink){
//             min=L;
//             L=L->next;
//             break;
//         }
//         L=L->next;
//     }
//     while(L->next){
//         if(L->data>=maxk){
//             max=L;
//             break;
//         }
//         L=L->next;
//     }
//     min->next=max;


// }

// void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
//     if(!L->next){
//         return;
//     }
//     Node *p,*s,*temp;
//     temp=L->next;
//     while(temp->next){
//         s=temp->next;
//         while(s->data>mink&&s->data<maxk){
//             p=s;
//             s=s->next;
//             free(p);
//         }
//         temp=temp->next;
//         if(s->data>=maxk){
//             temp->next=s;
//             break;
//         }
//     }
// }