// 栈 后缀表达式计算

// 请使用已定义好的栈完成后缀表达式计算：
// (1)如果是操作数，直接入栈
// (2)如果是操作符op，连续出栈两次，得到操作数x 和 y,计算 x op y，并将结果入栈。

// 后缀表达式示例如下：
// 9  3  1  -  3  *  +  10  2  /  +
// 13  445  +  51  /  6  -
// 操作数、操作符之间由空格隔开，操作符有 +，-，*, /, %共 5 种符号，所有操作数都为整型。

// 栈的定义如下：

// #define Stack_Size 50
// typedef struct{
//     ElemType elem[Stack_Size];
//     int top;
// }Stack;

// bool push(Stack* S, ElemType x);
// bool pop(Stack* S, ElemType *x);
// void init_stack(Stack *S);
// 其中，栈初始化的实现为：

// void init_stack(Stack *S){
//     S->top = -1;
// }
// 需要完成的函数定义为：int compute_reverse_polish_notation(char *str);

// 函数接收一个字符指针，该指针指向一个字符串形式的后缀表达式，函数返回该表达式的计算结果。
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElemType;
#define Stack_Size 50
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S);

void init_stack(Stack *S){
    S->top = -1;
}
// int compute_reverse_polish_notation(char *str){
//     ElemType number,n1,n2;
//     Stack S;
//     init_stack(&S);
//     for(int k=0;str[k]!='\0';k++){
//         if(str[k]!=' '){
//             if(str[k]>='0'&&str[k]<='9'){
//                 number=0;
//                 while(str[k]!=' '&&str[k]!='\0'){
//                     number=number*10+(str[k]-'0');
//                     k++;
//                 }
//                 push(&S,number);
//             }
            // else {
            //     pop(&S,&n1);
            //     pop(&S,&n2);
            //     switch(str[k]){
            //     case '+':{
            //             n1+=n2;
            //             break;}
            //     case '-':{
            //             n1-=n2;
            //             break;}
            //     case '*':{
            //             n1*=n2;
            //             break;}
            //     case '/':{
            //             n1/=n2;
            //             break;}
            //     case '%':{
            //             n1%=n2;
            //             break;}
            //     }
            //     push(&S,n1);
            // }
            
//         }
//     }
//     pop(&S,&number);
//     return number;
// }

// int main(){
//     // char c=1,h=2,y='A',p=57;
//     // int f=c+h,q=p;
//     // printf("%d\n",f);
//     // printf("%d\n",y);
//     // printf("%c",p);
//     // printf("%c",q);
//     char str = "9  3  1 + \0";

//     compute_reverse_polish_notation(str);
//     return 0;
// }

int compute_reverse_polish_notation(char *str){
    ElemType number,n1,n2;
    Stack S;
    init_stack(&S);
    for(int k=0;str[k]!='\0';k++){
        if(str[k]!=' '){
            if(str[k]>='0'&&str[k]<='9'){
                number=0;
                while(str[k]!=' '&&str[k]!='\0'){
                    number=number*10+(str[k]-'0');
                    k++;
                }
                push(&S,number);
            }
            else {
                pop(&S,&n2);
                pop(&S,&n1);
                switch(str[k]){
                    case '+':
                    n1+=n2;
                    break;
                    case '-':
                    n1-=n2;
                    break;
                    case '*':
                    n1*=n2;
                    break;
                    case '/':
                    n1/=n2;
                    break;
                    case '%':
                    n1%=n2;
                    break;
                }
                push(&S,n1);
            }
            
        }
    }
    pop(&S,&number);
    return number;
}
