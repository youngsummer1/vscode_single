#include<stdio.h>


//数论

//题目1 全部相同


// //求最大公约数
// int gcd(int a,int b ){
//     while(b != 0){
//         int temp = a;
//         a = b;
//         b = temp % b;
//     }
//     return a;
// }

// //找出最小值
// //将最小值放到第一个
// void find_min(int num[], int length){
//     int min = 0, i;
//     for(i = 1; i < length; i++){
//         if(num[min] > num[i])min = i;
//     }
//     int temp = num[0];
//     num[0] = num[min];
//     num[min] = temp;
// }

// //找出使其相等的k
// int to_same(int num[], int length){
//     int flag = 1; //记录num各个数是否全部相同
//     find_min(num, length);
//     for(int i = 1; i < length; i++){
//         num[i] -= num[0];
//         if(num[i] != 0)flag = 0;
//     }

//     if(flag == 1)return -1;

//     int answer = gcd(num[1],num[2]);
//     for(int i = 3;i < length; i++){
//         answer = gcd(answer, num[i]);
//     }
//     return answer;
// }

// #define N 50
// // #define H 10000
// int main(){
//     int t , n;
//     int num[N], answer;
//     scanf("%d", &t);
//     for(int i = 0; i < t; i++){
//         scanf("%d", &n);
//         for(int j = 0; j < n; j++)scanf("%d",&num[j]);
//         answer = to_same(num, n);
//         printf("%d\n",answer);
//     }

//     return 0;
// }


//题目2 石头剪刀布
// #include<string.h>

// char first[1000],second[1000];
// int fir_lost = 0, sec_lost = 0;
// //求最大公约数
// int gcd(int a,int b ){
//     while(b != 0){
//         int temp = a;
//         a = b;
//         b = temp % b;
//     }
//     return a;
// }

// //求最小公倍数
// int lcm(int a, int b){
//     return a * b / gcd(a,b);
// }

// void w_or_l(int fir, int sec){
//     if(first[fir] == 'R' && second[sec] == 'P')fir_lost++;
//     if(first[fir] == 'R' && second[sec] == 'S')sec_lost++;

//     if(first[fir] == 'P' && second[sec] == 'R')sec_lost++;
//     if(first[fir] == 'P' && second[sec] == 'S')fir_lost++;

//     if(first[fir] == 'S' && second[sec] == 'R')fir_lost++;
//     if(first[fir] == 'S' && second[sec] == 'P')sec_lost++;
// }

// int main(){
//     int num;
//     scanf("%d",&num);
//     scanf("%s",first);
//     scanf("%s",second);
//     int len_f = strlen(first), len_s = strlen(second);
//     int cycle = lcm(len_f, len_s);
//     for(int i = 0; i < cycle; i++){
//         w_or_l(i % len_f, i % len_s);
//     }
//     fir_lost *= num / cycle;
//     sec_lost *= num / cycle;

//     for(int i = 0; i < num % cycle; i++){
//         w_or_l(i % len_f, i % len_s);
//     }
//     printf("%d %d",fir_lost,sec_lost);

//     return 0;
// }




int main(){
    int num[20];
    int cnt = 0;
    for(int i = 0;i<10;i++)num[++cnt] = i;

    printf("%d",num[1]);
    return 0;
}