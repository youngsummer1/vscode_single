#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//题目三 假期堵车

// int main(){
//     int res = 1, n, t;
//     int a[107];

//     scanf("%d %d", &n, &t);
//     for(int i = 0; i < n; i++)scanf("%d", &a[i]);

//     for(int i = 0; i < n; i++){
//         if(0 < a[i] < 1380){
//             t = t - (1440 - a[i]);
//             if(t <= 0)break;
//         }
//         res++;

//     }
//     printf("%d",res);
//     return 0;
// }

// #define N 1000000
// #define N 1000
// char num_1[N], num_2[N], str_1[N], str_2[N];
// //字符串的最小表示法
// //这里直接使用char类型，没什么影响，输出时变成%c就好
// int min_Num(char num[], int len){
//     for(int i = 0; i < len; i++)num[len + i] = num[i];
//     int i = 0, j = 1, k;
//     while(i < len && j < len){
//         for(k = 0; k < len && num[i + k] == num[j + k]; k++);
//         if(k == len)break;

//         if(num[i + k] > num[j + k]){
//             i = i + k + 1;
//             if(i == j)i++;
//         }

//         else{
//             j = j + k + 1;
//             if(i == j)j++;
//         }
//     }
//     //小的那个代表的是最小表示的起点
//     int res = (i < j) ?i :j;
//     return res;
//     // for(int a = 0; a < len; a++)printf("%c", num[res + a]);
// }

// int main(){
//     int len_1, len_2, pos1, pos2;
//     // char str[100];
//     // scanf("%s", str);
//     // len = strlen(str);
//     // for(int i = 0; i < len; i++)printf("%c", str[i]);

//     scanf("%s", num_1);
//     scanf("%s", num_2);
//     // //检查是否同构
//     int i = 0, j = 0;
//     len_1 = strlen(num_1);
//     len_2 = strlen(num_2);
//     pos1 = min_Num(num_1, len_1);
//     pos2 = min_Num(num_2, len_2);
    
//     for(i = 0; i < len_1; i++){
//         str_1[i] = num_1[(pos1 + i) % len_1];
//     }
//     for(j = 0; j < len_2; j++){
//         str_2[j] = num_2[(pos2 + j) % len_2];
//     }
//     if(strcmp(str_1, str_2) == 0){
//         printf("Yes\n");
//         printf("%s", str_1);
//     }
//     else printf("No");
//     // strcat(num_1, num_1);
//     // strcat(num_2, num_2);
//     // if(len_1 == len_2){
//     //     while(j < len_2){
//     //         for(k = 0; k < len_1 && num_1[i + k] == num_2[j + k]; k++);
//     //         if(k == len_1)break;
//     //         j++;
//     //     }
//     //     if(k == len_1){
//     //         printf("Yes\n");
//     //         min_Num(num_1, len_1);
//     //         return 0;
//     //     }
//     // }
//     // printf("No");
//     return 0;
// }


//上面的过了，下面的没过，没找到下面内容没过的点

// #define N 2000007
// char num_1[N], num_2[N];
// //字符串的最小表示法
// //这里直接使用char类型，没什么影响，输出时变成%c就好
// void min_Num(char num[], int len){
//     // for(int i = 0; i < len; i++)num[len + i] = num[i];
//     int i = 0, j = 1, k;
//     while(i < len && j < len){
//         for(k = 0; k < len && num[i + k] == num[j + k]; k++);
//         if(k == len)break;

//         if(num[i + k] > num[j + k]){
//             i = i + k + 1;
//             if(i == j)i++;
//         }

//         else{
//             j = j + k + 1;
//             if(i == j)j++;
//         }
//     }
//     //小的那个代表的是最小表示的起点
//     int res = (i < j) ?i :j;
//     for(int a = 0; a < len; a++)printf("%c", num[res + a]);
// }

// int main(){
//     int len_1, len_2;
//     // char str[100];
//     // scanf("%s", str);
//     // len = strlen(str);
//     // for(int i = 0; i < len; i++)printf("%c", str[i]);
//     scanf("%s", num_1);
//     scanf("%s", num_2);
//     //检查是否同构
//     int i = 0, j = 0, k;
//     len_1 = strlen(num_1);
//     len_2 = strlen(num_2);
//     strcat(num_1, num_1);
//     strcat(num_2, num_2);
//     if(len_1 == len_2){
//         while(j < len_2){
//             for(k = 0; k < len_1 && num_1[i + k] == num_2[j + k]; k++);
//             if(k == len_1)break;
//             j++;
//         }
//         if(k == len_1){
//             printf("Yes\n");
//             min_Num(num_1, len_1);
//             return 0;
//         }
//     }
//     printf("No");
//     //return 0;
// }

//题目五 3d眩晕
// #define N 100000
#define N 100

int diff = 0;
void check(char s0[], char s[], int left, int s_len){
    diff = 0;
    for(int i = 0; i < s_len; i++){
        if(s0[left + i] != s[i])diff++;
    }
}

int main(){
    int left = 0, res = 0, T, len1, len2; 
    char S0[N] , S[N];
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        res = 0;
        scanf("%s", &S0);
        scanf("%s", &S);
        len1 = strlen(S0);
        len2 = strlen(S);
        for(left = 0; left <= len1 - len2; left++){
            check(S0, S, left, len2);
            if(diff <= 3)res++;
        }
        printf("%d", res);
    }

    return 0;
}