#include<stdio.h>
#include<string.h>
//题目一 长度最小的连续子数组

// #define N 100000
// int num[N];

// int min(int a, int b){
//     return (a < b) ?a :b;
// }

// int main(){
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for(int i = 0; i < n; i++)scanf("%d", &num[i]);

//     int sum = 0, left = 0, right = 0, min_len = N;

//     while(right < n){
//         sum += num[right];
//         while(sum >= m){
//             min_len = min(min_len, right - left + 1);
//             sum -= num[left];
//             left++;
//         }
//         right++;
//     }

//     if(min_len == N)printf("0");
//     else printf("%d", min_len);

//     return 0;
// }


//题目二 无重复字符的最长子串
// // #define N 100007
// #define N 1007

// static int cnt[300];
// static char s[N];
// int maxLength(char arr[], int arrLength){
//     if(arrLength <= 1) return arrLength;
//     int maxlen = 0;
//     int left = 0, right = 0;
//     while(right < arrLength){
//         cnt[(int)arr[right]]++;
//         while(cnt[(int)arr[right]] > 1){
//             cnt[(int)arr[left]]--;
//             left++;
//         }
//         right++;
//         maxlen = maxlen > (right - left) ? maxlen : (right - left );
//     }
//     return maxlen;
// }

// int main(){

//     gets(s);

//     int maxlen = maxLength(s, strlen(s));

//     printf("%d", maxlen);
// }
