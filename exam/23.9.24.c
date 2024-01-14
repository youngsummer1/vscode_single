#include<stdio.h>

//题目1 欧拉函数
// int euler_phi(int n){
//     int answer = n;
//     for(int i = 2; i * i <=n; i++){
//         if(n % i == 0){
//             answer = answer / i * (i-1);
//             while(n % i == 0) n /= i;
//         }
//     }
//     if(n > 1)answer = answer / n * (n-1);
//     return answer;
// }

// int main(){
//     int n, ans;
//     scanf("%d",&n);
//     ans = euler_phi(n);
//     printf("%d",ans);
// }


//题目2 欧拉函数2
#define N 1000000
int is_prime[N],prime[N],phi[N];

void pre(int n){
    for(int i = 1; i <= n;i++)is_prime[i] = 1;

    int cnt = 0;
    is_prime[1] = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[++cnt] = i;
            phi[i] = i-1;
        }
        for (int j = 1; j <= cnt && 1ll * i * prime[j] <= n; j++){
            is_prime[i * prime[j]] = 0;
            if(i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else{
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}

// void pre() {
// 	//is_prime[i]全部置1
//   for (int i = 1; i <= 50000; i++) {
//     is_prime[i] = 1;
//   }
//   int cnt = 0;
//   is_prime[1] = 0;
// 	//规定
//   phi[1] = 1;
//   for (int i = 2; i <= 50000; i++) {
//     if (is_prime[i]) {
// 		//写错了吧，应该是cnt++
// 		//没写错，cnt++会报错，再想想
//       prime[++cnt] = i;
//      //欧拉函数的性质，i是质数的话 phi[i] = i - 1
// 			phi[i] = i - 1;
//     }
//     for (int j = 1; j <= cnt && i * prime[j] <= 50000; j++) {
//       is_prime[i * prime[j]] = 0;
//       if (i % prime[j])
//         phi[i * prime[j]] = phi[i] * phi[prime[j]];
//       else {
// 		  //这里break为什么，再想想
//         phi[i * prime[j]] = phi[i] * prime[j];
//         break;
//       }
//     }
//   }
// }

int main(){
    int n;
    long long ans = 0;
    scanf("%d",&n);
    pre(n);
    for(int i = 1; i <= n; i++){
        ans += phi[i];
        // printf("%d\n",phi[i]);
    }
    printf("%lld",ans);
    return 0;
}