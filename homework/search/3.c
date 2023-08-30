// AVL添加

// 平衡二叉树，是一种二叉排序树，其中每个结点的左子树和右子树的高度差至多等于1。它是一种高度平衡的二叉排序树。现二叉平衡树结点定义如下：

// typedef struct node
// {
//     int val;
//     struct node *left;
//     struct node *right;
//     struct node *parent;
//     int height;
// } node_t;
// 请实现平衡二叉树的插入算法：

// //向根为 root 的平衡二叉树插入新元素 val，成功后返回新平衡二叉树根结点
// node_t *avl_insert(node_t *root, int val);

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} node_t;
node_t *avl_insert(node_t *root, int val);

void update(node_t* root)
{
    if (root == NULL)
        return;
    int h = 1;
    if (root->left) {
        int lh = root->left->height + 1;
        h = lh > h ? lh : h;
        root->left->parent = root;
    }
    if (root->right) {
        int rh = root->right->height + 1;
        h = rh > h ? rh : h;
        root->right->parent = root;
    }
 
    root->height = h;
}
void LL(node_t** t)
{
    node_t* tmp = (*t)->left;
    (*t)->left = tmp->right;
    tmp->right = (*t);
    (*t) = tmp;
 
    update((*t)->right->left);
    update((*t)->right);
    update((*t));
}
void RR(node_t** t)
{
    node_t* tmp = (*t)->right;
    (*t)->right = tmp->left;
    tmp->left = (*t);
    (*t) = tmp;
 
    update((*t)->left->right);
    update((*t)->left);
    update((*t));
}
 
void LR(node_t** t)
{
    RR(&(*t)->left);
    LL(t);
}
void RL(node_t** t)
{
    LL(&(*t)->right);
    RR(t);
}
 
node_t* avl_insert(node_t* root, int val)
{
    if (root == NULL) {
        node_t* rt = (node_t*)malloc(sizeof(node_t));
        rt->left = rt->right = rt->parent = NULL;
        rt->height = 1;
        rt->val = val;
 
        return rt;
    }
 
    if (val <= root->val) {
        root->left = avl_insert(root->left, val);
        int left_h = root->left->height;
        int right_h = root->right ? root->right->height : 0;
 
        if (left_h - right_h > 1) {
            if (val <= root->left->val) {
                LL(&root);
            } else {
                LR(&root);
            }
        }
    } else {
        root->right = avl_insert(root->right, val);
        int left_h = root->left ? root->left->height : 0;
        int right_h = root->right->height;
 
        if (right_h - left_h > 1) {
            if (val > root->right->val) {
                RR(&root);
            } else {
                RL(&root);
            }
        }
    }
 
    update(root);
    return root;
}