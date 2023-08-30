#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//KMP算法
typedef struct{
    char data[1000000];
    int length;
}SqString;

void GetNext(SqString t,int next[]){

    int j,k;
    j=0,k=-1;
    next[0]=-1;
    while(j<t.length){
        if(k==-1||t.data[j]==t.data[k]){
            j++;k++;
            next[j]=k;
            //k在前，j在后，k即为与后缀相同的最长前缀的最后一个字符的下标
        }
        else{
            //k<=j,所以next[k]是已经定义过的
            k=next[k];

        }
    }
}

int KMPIndex(SqString s,SqString t)
{
    int next[300000],i=0,j=0;
    GetNext(t,next);
    while (i<s.length && j<t.length)
    {
        if(j==-1|| s.data[i]==t.data[j]){
            i++;j++;
        }
        else j=next[j];
    }
    if(j>=t.length)return (i-t.length);
    
    else return -1;


}


//题1字符串构造
// int main(){
//     int k,next[300000],count=0;
//     char s[300000];
//     SqString t;
//     scanf("%d %d",&t.length,&k);
//     scanf("%s",t.data);

//     GetNext(t,next);
    
//     int i=0,j=0;

//     while(count<k){
//         while(j<t.length){
//             s[i++]=t.data[j++];
//         }
//         j=next[t.length];
//         count++;
//     }
//     printf("%s",s);

//     return 0;
// }


//题2 密码
//70分，不知道什么条件没考虑到
// int main(){
//     SqString S;
//     int next[1000000];
//     scanf("%s",S.data);
//     S.length = strlen(S.data);

//     GetNext(S,next);
//     char search[1000000],temp[10000];
//     for(int i=0,k=1;k<S.length-1;){
//         search[i++]=S.data[k++];

//     }
//     search[S.length-2] = '\0';

//     int location = S.length;
//     int count = next[location];
//     while(count>0){
//         for(int i=0;i<count;i++)temp[i]=S.data[i];
//         if(strstr(search,temp) != NULL){
//             printf("%s",temp);
//             return 0;
//         }
//         else{
//             location = count ;
//             count = next[location];
//         }

//     }

//     printf("Just a legend");

//     return 0;
// }


//题3 最漂亮的工艺品
// #define N 600000
//虽然题目限制是300000，但我复制了一遍所以要翻倍
#define N 300
// int Min_String(char s[]){
//     int len = strlen(s);
//     strcat(s,s);

//     int i=0,j=1,k;

//     while(i<len && j<len){
//         for(k=0 ; k<len && s[i+k] == s[j+k] ; k++);
//         if(k == len)break;

//         if(s[i+k]>s[j+k]){
//             i = i+k+1;
//             if(i == j)i++;
//         }
//         else{
//             j = j+k+1;
//             if(i == j) j++;
//         }

        
//     }
//      return (i<j)?i :j;
// }

//按数字排
// int Min_Num(int s[],int len){
//     for(int h=0; h<len ; h++)s[h+len] = s[h];

//     int i=0,j=1,k;

//     while(i<len && j<len){
//         for(k=0 ; k<len && s[i+k] == s[j+k] ; k++);
//         if(k == len)break;

//         if(s[i+k]>s[j+k]){
//             i = i+k+1;
//             if(i == j)i++;
//         }
//         else{
//             j = j+k+1;
//             if(i == j) j++;
//         }

        
//     }
//     return (i<j)?i :j;
// }

// int main(){
//     int n ,num[N],loc;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++)scanf("%d",&num[i]);

//     loc = Min_Num(num,n);

//     for(int i=loc,count=0;;i++){
//         if(i==n){
//             i=0;
//             count=1;
//         }
//         if(i==loc&&count==1)break;
//         printf("%d ",num[i]);
//     }
//     return 0;
// }

//字符串版
// int main(){
//     int n ,loc;
//     char str[N];
//     scanf("%d",&n);
//     scanf("%s",str);

//     loc = Min_String(str);

//     for(int i=loc,count=0;;i++){
//         if(i==n){
//             i=0;
//             count=1;
//         }
//         if(i==loc&&count==1)break;
//         printf("%c",str[i]);
//     }
//     return 0;
// }


//题目4 三进制计算机1
// #define N 1000000

// int main(){
//     int pi[100];
//     pi[0] = 1;
//     for(int i = 1; i<100 ;i++)pi[i]=pi[i-1]*3;

//     int n,ten[N];
//     scanf("%d",&n);

//     for(int i=0; i<n ; i++){
//         char num[100];
//         int ans = 0, len;
//         scanf("%s",num);
//         len = strlen(num);

//         for(int k=len-1 ;k>=0 ;k--){
//             if(num[k]=='1'){
//                 ans+= pi[len-1-k];
//             }
//             if(num[k]=='-'){
//                 ans-= pi[len-1-k];
//             }

//         }
//         ten[i]=ans ;

//     }
//     for(int i=0; i<n; i++)printf("%d\n",ten[i]);

//     return 0;
// }


//题目5 三进制计算机2

// typedef struct{
//     int num[100];
//     int len;
// }ternary_t;

// ternary_t ternary(int num){
//     ternary_t ternary_num;
//     ternary_num.len=0;
//     for(int i =0;num>0;i++ ){
//         int temp = num/3 ;
//         int rem = num%3;
//         ternary_num.num[i] = rem;
//         num = temp;
//         ternary_num.len++;
//     }
//     return ternary_num;
// }

// int main(){


//     for
// }