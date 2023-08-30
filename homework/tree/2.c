// 路径

// 假设二叉树采用二叉链表方式存储， root指向根结点，node 指向二叉树中的一个结点，编写函数 path，计算root到 node 之间的路径，（该路径包括root结点和 node 结点）。path 函数声明如下：

// bool path(BiTNode* root, BiTNode* node, Stack* s);
// 其中，root指向二叉树的根结点，node指向二叉树中的另一结点，s 为已经初始化好的栈，该栈用来保存函数所计算的路径，如正确找出路径，则函数返回 true，此时root在栈底，node在栈顶；如未找到，则函数返回 false, 二叉树的相关定义如下：

// typedef int DataType;

// typedef struct Node{
//     DataType data;
//     struct Node* left;
//     struct Node* right;
// }BiTNode, *BiTree;
// 栈的相关定义及操作如下：

// #define Stack_Size 50
// typedef BiTNode* ElemType;
// typedef struct{
//     ElemType elem[Stack_Size];
//     int top;
// }Stack;

// void init_stack(Stack *S); // 初始化栈
// bool push(Stack* S, ElemType x); //x 入栈
// bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
// bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
// bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false
// 在提示中，树用缩进的形式展示，如二叉树 ，其缩进形式为：。

#include<stdbool.h>
#include<stdio.h>
typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;

#define Stack_Size 50
typedef BiTNode* ElemType;
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false

bool path(BiTNode* root, BiTNode* node, Stack* s){
    BiTNode* temp,*p=NULL;
    temp=root;
    if(temp==NULL||!is_empty(s)||node==NULL)return false;
    while(!is_empty(s)||temp!=NULL){
        while(temp!=NULL){
            push(s,temp);
            if(temp==node)return true;
            temp=temp->left;
        }
        top(s,&temp);
        if(!temp->right||temp->right==p){
            // 第二个条件是，一直往右的情况，不加这个会无限循环（删掉temp后回到它的双亲结点，不加第二个条件temp又会取它的右节点）
            p=temp;
            pop(s,&temp);
            temp=NULL;//是为了让它跳过上面的那个while循环
        }
        else temp=temp->right;
    }
    return false;
}


// bool path(BiTNode* root, BiTNode* node, Stack* s)
// {
//     BiTree T = root, p=NULL;
//     if (T == NULL || node == NULL || !is_empty(s))
//         return false;
//     while (T || !is_empty(s)) {
//         while (T) {
//             push(s, T);
//             if (T == node)
//                 return true;
//             T = T->left;
//         }
//         top(s, &T);
//         if (!T->right || T->right == p) {
//             p = T;
//             pop(s, &T);
//             T = NULL;
//         } else
//             T = T->right;
//     }
//     return false;
// }
