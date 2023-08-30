// 块链串

// 块链串定义如下：

// #define BLOCK_SIZE 4    // 可由用户定义的块大小
// #define BLS_BLANK '#'   // 用于空白处的补齐字符

// typedef struct _block {
//     char ch[BLOCK_SIZE];    //块的数据域
//     struct _block *next;    //块的指针域
// } Block;

// typedef struct {
//     Block *head;        // 串的头指针
//     Block *tail;        // 串的尾指针
//     int len;            // 串的当前长度
// } BLString;

// //字符串初始化函数：
// void blstr_init(BLString *T) {
//     T->len = 0;
//     T->head = NULL;
//     T->tail = NULL;
// }
// 这些定义已包含在头文件 dsstring.h 中，请实现块链串的子串查找操作：

// bool blstr_substr(BLString src, int pos, int len, BLString *sub);
// src为要查找的字符串
// pos为子串开始的下标
// len为子串的长度
// sub在函数调用运行前指向一个已经初始化好的空串，在函数返回时，sub指向串src从第pos个字符起长度为len的子串
// 函数查找成功返回true，参数不正确返回 false
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;

//字符串初始化函数：
void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}

int linecpy(BLString* src,const char* str){
    int block_num=strlen(str)/BLOCK_SIZE,block_pos=strlen(str)%BLOCK_SIZE;
    int h=0;
    Block* q,*temp;
    src->len=strlen(str);
    if(src->len<=0)return 0;
    if(block_pos>0)block_num++;
    for(int i=0;i<block_num;i++){
        q=(Block*)malloc(sizeof(Block));
        if(NULL==q)return 0;
        for(int h=0;h<BLOCK_SIZE&&*str;h++){
            *(q->ch+h)=*str++;
        }
        if(i==0){
            src->head=temp=q;
        }
        else{
            temp->next=q;
            temp=q;
        }
        if(!*str){
            for(;h<BLOCK_SIZE;h++)*(q->ch+h)=BLS_BLANK;
            src->tail=temp;
            temp->next=NULL;
        }

    }
    return 1;
}

bool blstr_substr(BLString src, int pos, int len, BLString *sub){
    char str[50];
    if(len<1||pos>=src.len||pos<0)return false;
    int position_block=pos/BLOCK_SIZE;
    int i=pos%BLOCK_SIZE;
    int j=0;
    Block* temp=src.head;
    for(j=0;j<position_block;j++)temp=temp->next;

    for(j=0;j<len;j++){
        if(i>=BLOCK_SIZE){
            temp=temp->next;
            i=0;
        }
        else{
            if(!temp||temp->ch[i]==BLS_BLANK)break;
            str[j]=temp->ch[i];
            i++;
        }
    }
    str[i]='\0';
    linecpy(sub,str);
    return true;

}


// int len(const char* s)
// {
//     int q = 0;
//     while (*s != '\0') {//可以简化while(*s++) q++;
//         q++;
//         s++;//!!!
//     }
//     return q;
// }
//易错点分析:
//1. 对于字符指针的操作, len函数书写
//2. 对于块的个数边界条件判定
//3. 对于块指针操作,分类讨论
//4. 尾指针置空,空白地方用'#'填充 

int StrAssign(BLString* S, const char* cstr)
{//将cstr复制到块链串S中
 
    int i, j, k, len;
    Block *p, *q;
    len = strlen(cstr); //len为链串的长度
    if (len == 0)
        return 0;
    S->len = len;
    
    j = len / BLOCK_SIZE; //j为链串的结点数 ,也就是块个数` 
    if (len % BLOCK_SIZE)
        j++;
        
    for (i = 0; i < j; i++) {
        p = (Block*)malloc(sizeof(Block));
        if (!p)
            return 0;//可以简化
            
        //k指示每一个块内部字符ch[]下标
        for (k = 0; k < BLOCK_SIZE && *cstr; k++) //将字符串ctrs中的字符赋值给链串的数据域
            *(p->ch + k) = *cstr++;//!!!!!!
            
        if (i == 0) //如果是第一个结点
            S->head = q = p; //头指针指向第一个结点
        else {//q为跟踪指针 
            q->next = p;
            q = p;
        }
        if (!*cstr) //如果是最后一个链结点
        {
            S->tail = q; //将尾指针指向最后一个结点
            q->next = NULL; //将尾指针的指针域置为空
            for (; k < BLOCK_SIZE; k++) //最后一个结点用'#'填充
                *(q->ch + k) = BLS_BLANK;
        }
    }
    return 1;
}
bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    char* t;
    if (pos < 0 || pos >= src.len || len < 1)
        return false;
    int n = pos / BLOCK_SIZE, h = pos % BLOCK_SIZE;
    Block* temp = src.head;
    
    for (int i = 0; i < n; i++)
        temp = temp->next;//temp直接指向pos位置那个块 
    
    char str[100];
    int i = 0;
    while (i < len) {
        if (h >= BLOCK_SIZE) {
            temp = temp->next;
            h = 0;
        } 
        else {
            if (!temp || temp->ch[h] == BLS_BLANK)
                break;
            str[i++] = temp->ch[h++];
        }
    }
    str[i] = '\0';
    StrAssign(sub, str);
    return true;
}