#include<stdio.h>
#include<string.h>
//双指针 + 排序


//题目一 无重复字符的最长子串
// #define N 100007
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


//题目二 最小子串覆盖
//注意 题目给的条件，若字串存在则唯一，是指最短的字串唯一（其实这个对于算法没什么区别）
// #define N 1000

// static int cnt_tar[200], cnt_sou[200];

// void min_len(char source[], char target[]){
//     int tar_len = strlen(target), sou_len = strlen(source);

//     if(sou_len < tar_len) {
//         printf("No");
//         return; 
//     }
//     //记录target的字母及数量
//     for(int i = 0; i < tar_len; i++){
//         cnt_tar[(int)target[i]]++;
//     }

//     //匹配开始
//     //sum —— 有多少字母匹配
//     //注意 题目给的条件，若字串存在则唯一
//     int sum = 0, left = 0, right = 0, min_length = N, min_left = 0;
//     while(right < sou_len){
//         //每一轮都会找到一个匹配的字串，找到最小的

//         //先把范围锁定，下一个循环再去缩小
//         while(right < sou_len){
//             if(cnt_tar[(int)source[right]] == 0 && cnt_tar[(int)source[left]] == 0){
//                 left++;
//                 right++;
//             }
//             else if(cnt_tar[(int)source[left]] > 0){
//                 if(cnt_tar[(int)source[right]] > 0){
//                     cnt_sou[(int)source[right]]++;
//                     if(cnt_sou[(int)source[right]] <= cnt_tar[(int)source[right]])sum++;
//                 }
//                 if(sum == tar_len)break;

//                 right++;
//             }
//         }
//         //缩小范围,因为上面是right一满足就直接退出，所以right已经是最小的了，这里只要缩left
//         if(sum == tar_len){
//             while(1){
//                 if(cnt_sou[(int)source[left]] > cnt_tar[(int)source[left]]){
//                     cnt_sou[(int)source[left]]--;
//                     left++;
//                 }
//                 else if(cnt_tar[(int)source[left]] == 0)left++;
//                 else if(cnt_sou[(int)source[left]] == cnt_tar[(int)source[left]])break;
                
//             }

//             if(min_length > (right - left + 1)){
//                 min_left = left;
//                 min_length = right - left + 1;
//             }

//             //right到最后一个的时候就直接出去了
//             // if(right == sou_len - 1)break;
//         }
        
//         //下一轮
//         cnt_sou[(int)source[left]]--;
//         sum--;
//         left++;
//         while(cnt_tar[(int)source[left]] == 0)left++;
//     }

//     //输出部分
//     if(min_length != N){
//         for(int i = min_left; i < min_length + min_left ; i++)printf("%c", source[i]);
//     }
//     else printf("No");
// }

// int main(){
//     char source[N], target[N];
//     scanf("%s", source);
//     scanf("%s", target);

//     min_len(source,target);
//     return 0;
// }


//题目三 方块桶
// #define N 1000007
// int main(){
//     int n, height[N];
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)scanf("%d", &height[i]);

//     int left = 0, l_MAX = 0, right = n -1,r_MAX = n - 1;
//     long long res = 0;
//     while(left < right){
//         if(height[l_MAX] > height[r_MAX]){
//             right--;
//             if(right == left)break;

//             if(height[right] > height[r_MAX]) r_MAX = right;
//             else{
//                 res += height[r_MAX] - height[right];
//             }
//         }
//         else{
//             left++;
//             if(right == left)break;

//             if(height[left] > height[l_MAX]) l_MAX = left;
//             else{
//                 res += height[l_MAX] - height[left];
//             } 
//         }
//     }

//     printf("%lld", res);
//     return 0;
// }