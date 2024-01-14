#include<stdio.h>

//题目1 越狱
int c = 1007;

long long divide(long long a, long long b){
    a %= c;
    long long res = 1;

    for(; b != 0; b /= 2){
        if(b % 2 == 1)
            res = (res * a) % c;
        a = (a * a) % c;
    }
    return res;
}

int main(){
    long long all_res, true_res, not_res;
    long long m, n;
    scanf("%lld %lld", &m, &n);

    //all_res 
    all_res = divide(m, n);
    //not_res
    not_res = divide(m-1, n-1);
    not_res = (m % c) * (not_res % c) % c;

    true_res = (all_res - not_res + c) % c;
    printf("%lld", true_res);

    // printf("m = %lld", divide(m,n));

    return 0;


}



//题目二 盒子与球
// int way[20][20];

// int main(){
//     for(int i = 0;i < 20; i++){
//         for(int j = 0;j < 20; j++){
//             way[i][j] = 0;
//         }
//     }
//     way[0][0] = 1;

//     int n, r;
//     scanf("%d %d",&n ,&r);
    
//     int num = 1;
//     for(int i = 1 ; i <= r ; i++)num *= i;


//     for(int i = 1; i <= n ; i++){
//         for(int j = 1; j <= i && j <= r; j++){
//             way[i][j] = way[i-1][j] * j + way[i-1][j-1];
//         }
//     }

//     printf("%d", way[n][r] * num);
//     return 0;
// }

//题目四 找朋友


//很奇怪这里，为什么%lld会被warning


// int main(){
//     long long n , m;
//     long long min, max;
//     scanf("%lld %lld",&n, &m);

//     //max
//     max = (n-m+1)*(n-m)/2;

//     //min
//     long long a_class, class_h, class_l;
//     a_class = n / m;
//     class_h = n - a_class * m;
//     class_l = m - class_h;

//     min = class_h * (a_class + 1) * a_class /2 + class_l * a_class * (a_class - 1) / 2;
//     printf("%lld %lld" ,min , max);



//     return 0;
// }




//题目五 点餐

// int main(){
//     int n,a,b,c;
//     scanf("%d %d %d %d",&n,&a,&b,&c);
//     if(a+b+c > 2*n)printf("NO");
//     else printf("YES");




//     return 0;
// }