// 树转二叉树

// 使用队列，编写transfrom函数，将普通树转换成对应的二叉树。二叉树的相关定义如下：

// typedef int DataType;

// typedef struct Node{
//     DataType data;
//     struct Node* left;
//     struct Node* right;
// }BiTNode, *BiTree;
// 普通树节点的定义如下：

// #define MAX_CHILDREN_NUM 5
// struct _CSNode
// {
//     DataType data;
//     struct _CSNode *children[MAX_CHILDREN_NUM];
// };
// typedef struct _CSNode CSNode;
// 其中，子树的根节点的指针存放在children数组的前k个元素中，即如果children[i]的值为NULL，而children[i-1]不为NULL，则表明该结点只有i棵子树，子树根结点分别保存在children[0]至children[i-1]中。

// 队列相关定义及操作如下：

// struct __Queue
// {
//     int i, j; //指向数组内元素的游标
//     void **array;
// };
// typedef struct __Queue Queue;

// Queue* create_queue(); //创建队列
// bool is_empty_queue(Queue *tree); //队为空返回true,不为空时返回false
// void* del_queue(Queue *tree); //结点指针出队
// void add_queue(Queue *tree, void *node); //结点指针入队
// void free_queue(Queue *tree); //释放队列
// transform函数定义如下：

// BiTNode* transform(CSNode *root);
// 其中 root 为普通树的根结点，函数返回该树对应二叉树的根结点。

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;

#define MAX_CHILDREN_NUM 5
struct _CSNode
{
    DataType data;
    struct _CSNode *children[MAX_CHILDREN_NUM];
};
typedef struct _CSNode CSNode;

struct __Queue
{
    int i, j; //指向数组内元素的游标
    void **array;
};
typedef struct __Queue Queue;

Queue* create_queue(); //创建队列
bool is_empty_queue(Queue *tree); //队为空返回true,不为空时返回false
void* del_queue(Queue *tree); //结点指针出队
void add_queue(Queue *tree, void *node); //结点指针入队
void free_queue(Queue *tree); //释放队列


//自己写的，没成功
// BiTNode* transform(CSNode *root){
//     // Queue* Q=create_queue();
//     BiTree tree, temp,pmove;
//     // CSNode* rear;
//     int i;
//     if(root==NULL)return NULL;
//     tree =(BiTNode*)malloc(sizeof(BiTNode));
//     tree->data=root->data;
//     tree->left=NULL,tree->right=NULL;
//     pmove=tree;

//     // while(pmove!=NULL){
//         for(i=0;root->children[i]!=NULL;i++){
//             temp=(BiTNode*)malloc(sizeof(BiTNode));
//             temp->data=root->children[i]->data;
//             temp->left=NULL,temp->right=NULL;
            
//             if(i=0){
//                 pmove->left=temp;
//                 pmove=pmove->left;
//             }
//             else{
//                 pmove->right=temp;
//                 pmove=pmove->right;
//             }
//             pmove=transform(root->children[i]);
//         }


//     // }
//     return tree;
// }


//抄的
BiTNode* transform(CSNode *root){
	if(!root) return NULL;
	
	Queue *que, *bque;
	
	BiTNode *p;
	//二叉树根结点创立 
	//小心点, 记得分配空间 
	p = (BiTNode *)malloc(sizeof(struct Node));
	p->data = root->data;
	p->left = p->right = NULL;
	 
	
	que = create_queue();
	bque = create_queue();
	//注意add_queue函数的返回值, 所以不用 xx = add_queue(xx)的形式
	add_queue(que, root);
	add_queue(bque, p);
	
	while(!is_empty_queue(que)){
		BiTree bq;//创建二叉树队列头结点(根结点) 
		bq = del_queue(bque);
		CSNode *q;
		q = del_queue(que);
		//第一次执行该操作就相当于建立了二叉树的根
		
		int i = 0; 
		BiTNode *former = NULL;
		
		for(i = 0; i < MAX_CHILDREN_NUM; i++){//递归形式
			if(q->children[i]){//判存在 
				BiTNode *bnode = (BiTNode *)malloc(sizeof(struct Node));
				bnode->data = q->children[i]->data;
				bnode->left = bnode->right = NULL; 
 
				//放置结点位置
				if(i == 0){
					bq->left = bnode;
				}
				else{//兄弟结点变成父子结点
					former->right = bnode;
				}
				former= bnode;
				
				add_queue(bque, bnode);
				add_queue(que, q->children[i]);
			}
		} 	
	}
	free(que->array);
//释放顺序不能错
	free(que);
	free(bque->array);
	free(bque);
	
	return p;
}