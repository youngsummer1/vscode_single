#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// //题目三 星辰大海 DFS
// #define N 20
// // #define N 84
// #define MOD 337077
// int res = 0, p, q, k, flag = 0;
// int vis[N][N];

// void dfs(int x, int y){
//     vis[x][y] = 1;
//     flag++;
//     if(flag == k){
//         res = (res + 1) % MOD;
//         flag--;
//         vis[x][y] = 0;
//         return ;
//     }

    
//     for(int j = y + 1; j <= q; j++){
//         if(flag != k && vis[x - 1][j] == 0 && vis[x + 1][j] == 0 &&vis[x][j + 1] == 0 &&vis[x][j - 1] == 0){
//             dfs(x, j);
//         }
//     }
    
//     for(int i = x + 1; i <= p; i++){
//         for(int j = 1; j <= q; j++){
//             if(flag != k && vis[i - 1][j] == 0 && vis[i + 1][j] == 0 &&vis[i][j + 1] == 0 &&vis[i][j - 1] == 0){
//                 dfs(i, j);
//             }
//         }
//     }
//     flag--;
//     vis[x][y] = 0;
    
// }

// int main(){
//     int T;
//     scanf("%d", &T);
//     for(int i = 0; i < T; i++){
//         res = 0;
//         scanf("%d %d %d", &p, &q, &k);
//         for(int j = 1; j <= p; j++){
//             for(int k = 1; k <= q; k++){
//                 dfs(j, k);
//             }
//         }
//         printf("%d\n", res);
//     }

//     return 0;
// }



//题目四 王国傀儡师
// #define ll long long
// #define MOD 3333
// int main(){
//     ll ans = 0;
//     ll n, temp;
//     scanf("%lld", &n);
//     // for(ll a = 1; a * a * a <= n; a++)
//     //     for(ll b = 1; a * b * b<= n; b++)
//     //         for(ll c = 1; a * b * c <= n; c++){
//     //             temp = a * b * c;
//     //             if(temp <= n)ans = (ans + 1) % N;
//     //         }
//     // ans = (ans + 3) % N;

//     //各不相同
//     for(int a = 1; a * a * a <= n; a++){
//         for(int b = a + 1; a * b * b <= n; b++){
//             temp = n / (a * b) - b;
//             if(temp > 0)
//                 ans = (ans + 6 * temp) % MOD;
//         }
//     }
//     //一小两大
//     for(int a = 1; a * a * a <= n; a++){
//         temp = sqrt(n / a) - a;
//         if(temp > 0)
//             ans = (ans + 3 * temp) % MOD;
//     }
//     //一大两小
//     for(int a = 1; a * a * a <= n; a++){
//         temp = n / (a * a) - a;
//         if(temp > 0)
//             ans = (ans + 3 * temp) % MOD;
//     }

//     //全相同
//     for(int a = 1; a * a * a <= n; a++){
//         ans = (ans + 1) % MOD;
//     }

//     printf("%lld", ans);

//     return 0;
// }



//题目五 多重堡垒
// #define N 10000
// int comp[N], weight[N];

// int count(int root, int now){
//     int floor = (int)ceil(log2(now + 1));
//     int max1, max2;
//     int left, right, l_root, r_root;
//     int fl_root = (int)ceil(log2(root + 1));

//     int n_wei = (floor - fl_root) * weight[now];
//     if(weight[2 * now] != 0 && weight[2 * now + 1] != 0){
//         //计算左右结点中
//         left = count(root, 2 * now);
//         right = count(root, 2 * now + 1);
//         max1 = fmax(left, right);
//         //以左右孩子为根节点继续
//         l_root = count(2 * now, 2 * now);
//         r_root = count(2 * now + 1, 2 * now + 1);

//         // int l_wei = (floor + 1 - root) * weight[2 * now];
//         // int r_wei = (floor + 1 - root) * weight[2 * now + 1];
//     }
//     else {
//         return n_wei;
//     }
//     max2 = fmax(max1, n_wei);

//     if(root == now){
//         comp[root] = max2;
//     }
//     return max2;
// }

// int main(){
//     int n, res = 0;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++)scanf("%d", &weight[i]);
//     count(1, 1);
//     for(int i = 1; i <= n; i++)res += comp[i];
//     printf("%d", res);

//     return 0;
// }