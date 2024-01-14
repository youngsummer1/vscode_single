#include<stdio.h>
#include<string.h>
//34周
//双指针

//题目一 战神的对称谜题
int main(){
    char str[5000];
    gets(str);
    int str_len = strlen(str);

    int left = 0, mid = 1, right = 2;
    int ll, mm, rr, max_len = 1, num = 0;

    //可能要改成mid？
    while(mid < str_len){
        while((str[left] != str[right]) && (str[left] != str[mid])){
            left++, mid++, right++;
        }
        //奇数和偶数的情况应该都要算，而不是选择其中一个
        if(str[left] == str[right]){
            num = 1;
            while(1){
                num += 2;
                left-- ,right++;
                if((str[left] != str[right]) || (right >= str_len) || (left < 0))break;
            }
            if(num > max_len)max_len = num;
        }
        
        left = mid - 1;
        if(str[left] == str[mid]){
            num = 0;
            right = mid; //mid因为同时还作为定位，所以用right来代替mid后面进行遍历
            while(1){
                num += 2;
                left-- ,right++;
                if((str[left] != str[right]) || (right >= str_len) || (left < 0))break;
            }
            if(num > max_len)max_len = num;
        }
        mid++;
        left = mid - 1;
        right = mid + 1;

    }

    printf("%d", max_len);
    return 0;
}


// int main(){
//     char str[5000];
//     gets(str);
//     int str_len = strlen(str);

//     int left = 0, mid = 1, right = 2;
//     int ll, mm, rr, max_len = 1, num = 0;

//     for(int i = 0; i < str_len; i++){
//         int l = i - 1, r = i + 1;
//         while(l >= 0 && r < str_len && str[l] == str[r]){
//             if((r - l + 1) > max_len)max_len = r - l + 1;
//             l--, r++;
//         }
//         l = i , r = i + 1;
//         while(l >= 0 && r < str_len && str[l] == str[r]){
//             if((r - l + 1) > max_len)max_len = r - l + 1;
//             l--, r++;
//         }
//     }

//     printf("%d", max_len);
//     return 0;
// }




//题目二 元音字母
// #define N 100000

// // int hash[200];

// int main(){
//     char s[N];
//     int k;
//     scanf("%s", s);
//     scanf("%d", &k);
//     int s_len = strlen(s);
//     int left = 0, right = k - 1, sum = 0, max = 0;
    
//     for(int i = 0; i < k; i++){
//         if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'){
//             sum++;
//         }
//     }
//     max = sum;

//     while(right < s_len - 1){
//         if(s[left] == 'a'||s[left] == 'e'||s[left] == 'i'||s[left] == 'o'||s[left] == 'u')sum--;
//         // if(s[right] == 'a'||s[right] == 'e'||s[right] == 'i'||s[right] == 'o'||s[right] == 'u')sum--;
//         right++, left++;

//         // if(s[left] == 'a'||s[left] == 'e'||s[left] == 'i'||s[left] == 'o'||s[left] == 'u')sum++;
//         if(s[right] == 'a'||s[right] == 'e'||s[right] == 'i'||s[right] == 'o'||s[right] == 'u')sum++;
//         if(sum > max)max = sum;
//     }

//     printf("%d",max);
//     return 0;
// }


//题目五 求和
// int main(){
//     int X;
//     scanf("%d", &X);

//     int a = 1, b = 2, count = 0;
//     float sum;
//     while(b <= (X + 1) / 2){
//         sum = (a + b) * (b - a + 1) / 2;
//         if(sum <= X){
//             if(sum == X){
//                 count++; 
//                 printf("%d %d\n",a ,b);
//             }
//             b++;
//         }
//         else a++;
//     }
//     if(count == 0)printf("No");


    
//     return 0;
// }