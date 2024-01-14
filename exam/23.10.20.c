#include<stdlib.h>
#include<stdio.h>
//概率论 + 组合数学

//题目一 抽卡
// int main(){
//     int n;
//     double prob = 0.994, res = 1;
//     scanf("%d", &n);
    
//     if(n >= 90){
//         printf("100.000000%%");
//     }
//     else{
//         for(int i = 0; i < n; i++){
//             res *= prob ;
//         }
//         res = 100 * (1 - res);
//         printf("%.6lf%%",res);
//     }
//     return 0;

// }


//题目2 抽奖概率

// int main(){
//     int M ;
//     double res , temp = 1;
//     scanf("%d", &M);

//     for(int i = 1; i <= M; i++){
//         temp /= 2;
//         res += temp / i; 
//     }
//     printf("%.6lf",res);
//     return 0;
// }

//题目3 赌石

// int main(){
//     int n;
//     double res = 1;
//     scanf("%d",&n);
//     n /= 2;
//     for(int i = n - 1; i > 0;i--){
//         res *= (n - 1 + i) / (4.0 * i);
//         // printf("%.4lf",res);

//     }
//     printf("%.4lf",1 - res);

//     return 0;
// }



//题目四 甜甜花

// //快速幂
// long c = 12520;

// long long diviede (long long a, long long b){
//     a %= c;
//     long long res = 1;
//     for(; b != 0; b /= 2){
//         if (b % 2 == 1)
//             res = (res * a) % c;
//         a = (a * a) % c;
//     }
//     return res;
// }

// //质数
// #define N 10007
// int prime[N] , visit[N];

// void define_prime(int n){

    
// }

//上面为失败做法
// #define N 10000
// long c = 12520;

// long long class(long long n, long long m){
//     long long res = 1;
//     for(int i = 1; i <= m; i++){
//         res *= (float)(n - m + i) / i; 
//     }
//     return res;
// }

// int main(){
//     int n, m;
//     int a[108];

//     scanf("%d %d",&n ,&m );
//     for(int i =1; i <= m; i++ ) scanf("%d",&a[i]);

//     int k = 0;
//     long long res = 1;
//     for(int i = m; i >= 1; i--){
//         k += a[m];
//         res = (res % c) * (class( k, a[m]) % c) % c;
//     }
    
//     res = (res % c) * (class(n ,k ) % c) % c;
//     printf("%lld",res);

//     return 0;
// }

//不知道怎么弄，上面半对，下面是AC
// long c = 12520;

// long long class(long long n, long long m){
//     long long res = 1;
//     for(int i = 1; i <= m; i++){
//         res *= 1.0 * (n - m + i) / i; 
//     }
//     return (long long)res;
// }

// int main(){
//     int n, m;
//     int a[108];

//     scanf("%d %d",&n ,&m );
//     for(int i =1; i <= m; i++ ) scanf("%d",&a[i]);

//     int k = 0;
//     int res = 1;
//     for(int i = m; i >= 1; i--){
//         k += a[m];
//         res = (res * class( k, a[m])) % c;
//     }
    
//     res = (res * class(n ,k )) % c;
//     printf("%d",res);

//     return 0;
// }

//题目五 饭饭 饿饿

int main(){
    int n, k, w;
    long long res = 1;
    scanf("%d %d %d",&n ,&k ,&w);
    for(int i = 0; i < 3 * w ; i++){
        res *= k - i;
    }
    printf("%lld", res);

    return 0;
}