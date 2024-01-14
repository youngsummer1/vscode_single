#include<stdio.h>

// int main(){
//     printf("你好啊hello");
//     return 0;
// }


int main(){
    int num_1[10], num_2[10];
    int s0 = 0, s1 = 0; 
    for(int i = 0; i < 5; i++){
        num_1[++s0] = i;
        num_2[s1++] = i;
    }
    printf("hello");
    return 0;

}