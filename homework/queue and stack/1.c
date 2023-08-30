// 队列 循环链表表示队列

// 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），请完成下列任务：


// 1: 队列初始化，成功返回真，否则返回假： bool init_queue(LinkQueue *LQ);

// 2: 入队列，成功返回真，否则返回假： bool enter_queue(LinkQueue *LQ, ElemType x);

// 3: 出队列，成功返回真，且*x为出队的值，否则返回假 bool leave_queue(LinkQueue *LQ, ElemType *x);

// 相关定义如下：

// typedef struct _QueueNode {
//     ElemType data;          // 数据域
//     struct _QueueNode *next;      // 指针域
// }LinkQueueNode, *LinkQueue;

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct _QueueNode {
    ElemType data;          // 数据域
    struct _QueueNode *next;      // 指针域
}LinkQueueNode, *LinkQueue;

bool init_queue(LinkQueue *LQ)
{
    *LQ=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if(NULL==(*LQ))return false;

    (*LQ)->next=(*LQ);
    
    return true;
}

bool enter_queue(LinkQueue *LQ, ElemType x)
{
    LinkQueueNode* new_node=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if(NULL!=new_node){
	    new_node->data=x;
        new_node->next=(*LQ)->next;
        (*LQ)->next=new_node;
        (*LQ)=new_node;
        return true;
    }
    return false;
}

bool leave_queue(LinkQueue *LQ, ElemType *x)
{
    if((*LQ)->next==(*LQ)){
        return false;
    }
    LinkQueue p;
    p=(*LQ)->next->next;
	*x=p->data;
    if((*LQ)->next->next!=(*LQ)){
    (*LQ)->next->next=p->next;
    }
    else{
        (*LQ)=(*LQ)->next;
        (*LQ)->next=(*LQ);
    }
    free(p);
    return true;
}
