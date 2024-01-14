#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//图论专题  +  模拟算法


//题目一 匹配图

//想不通啊，为什么会有7个案例答案错误啊啊啊啊
//两两相连！！！！！！！！
//md好好看题目

// #define N 107
// #define M 10007
// #define MAX 100000000
// struct edge_type{
//     int next;
//     int val;
//     int to;
// } edge[M];

// int head[N], cnt = 0, n, m, visited[N], val[N];

// void init(){
//     memset(head, -1, sizeof(head));
//     memset(visited, 0, sizeof(visited));
// }

// int add(int from, int to, int val){
//     cnt++;
//     edge[cnt].val = val;
//     edge[cnt].to = to;
//     edge[cnt].next = head[from];
//     head[from] = cnt;
// }



// int min(int a, int b){
//     return (a <= b)? a : b ;
// }

// //floor为层数，到第三层就返回
// int dfs(int start, int from, int floor, int now, int res){
//     if(floor == 3){
//         for(int i = head[from]; i != -1; i = edge[i].next){
//             if(edge[i].to == start){
//                 visited[from] = 0;
//                 return min(res, now);
//             }
//         }
//         return res;
//     }
//     visited[from] = 1;


//     for(int i = head[from]; i != -1;i = edge[i].next){
//         int to = edge[i].to;
//         if(!visited[to]){
//             res = dfs(start, to, floor+1, now + val[to], res);
//         }
//     }

//     visited[from] = 0;
//     return res;

// }

// int main(){
//     init();

//     scanf("%d %d", &n, &m);
//     for(int i = 1; i <= n; i++)scanf("%d", &val[i]);
//     for(int i = 1; i <= m; i++){
//         int v , u;
//         scanf("%d %d", &v, &u);
//         add(v, u, 0);
//         add(u, v, 0);
//     }

//     int res = MAX;
//     for(int i = 1; i <= n; i++){
//         res = min(res, dfs(i, i, 1, val[i], res));
//     }
//     if(res == MAX)printf("-1");
//     else {printf("%d",res);}

//     return 0;
// }


// #define N 100
// #define MAX_NUM 1e7
// int adj[N][N], val[N], n, m;

// int min(int a, int b){
//     return (a <= b) ? a : b ;
// }

// int main(){

//     memset(adj, 0, sizeof(adj));
//     scanf("%d %d", &n, &m);
//     for(int i = 1; i <= n; i++)scanf("%d", &val[i]);
//     for(int i = 1; i <= m; i++){
//         int u, v;
//         scanf("%d %d", &u, &v);
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }

//     int res = MAX_NUM;
//     for(int i = 1; i <= n; i++){
//         for(int j = i + 1; j <= n; j++){
//             for(int k = j + 1; k <= n; k++){
//                 if(adj[i][j] == 1 && adj[j][k] == 1 && adj[i][k] == 1)
//                     res = min(res, val[i] + val[j] + val[k]);
//             }
//         }
//     }
    
//     if(res == MAX_NUM)printf("-1");
//     else printf("%d", res);


//     return 0;
// }


//题目二 过年访亲

//自己写的
//之前没考虑n为1的情况，应该输出0
// #define N 10
// #define MAX 1e6
// int adj[N][N], n, vis[N];

// int min(int a, int b){
//     return (a <= b) ? a : b;
// }

// int dfs(int to, int now, int res){
//     vis[to] = 1;
//     for(int i = 1; vis[i] == 1; i++){
//         if(i == n - 1){
//             vis[to] = 0;
//             return min(res, now + adj[to][0]);
//         }
//     }

//     for(int i = (to + 1) % n ; i != to; i = (i + 1) % n){
//         if(!vis[i]){
//             res = min(res, dfs(i, now + adj[to][i], res));
//         }
//     }

//     vis[to] = 0;
//     return res;
// }

// int main(){
//     memset(vis, 0, sizeof(vis));

//     scanf("%d", &n);
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             scanf("%d", &adj[i][j]);
//         }
//     }

//     int res = MAX;
//     vis[0] = 1;
//     for(int i = 1; i < n ; i++){
//         res = min(dfs(i, adj[0][i], res), res);

//     }
//     if(n == 1)printf("0");
//     else printf("%d", res);
//     return 0;
// }

//试试别人的
// #define N 10
// #define MAX 1e6
// int adj[N][N], n, vis[N];

// int min(int a, int b){
//     return (a <= b) ? a : b;
// }

// int dfs(int to, int now, int res, int floor){
//     vis[to] = 1;
//     if(floor == n ){
//         vis[to] = 0;
//         return min(res, now + adj[to][0]);
//     }

//     for(int i = (to + 1) % n ; i != to; i = (i + 1) % n){
//         if(!vis[i]){
//             res = min(res, dfs(i, now + adj[to][i], res, floor + 1));
//         }
//     }

//     vis[to] = 0;
//     return res;
// }

// int main(){
//     memset(vis, 0, sizeof(vis));

//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             scanf("%d", &adj[i][j]);
//         }
//     }

//     int res = MAX;
//     vis[1] = 1;
//     for(int i = 2; i <= n; i++){
//         res = min(dfs(i, adj[1][i], res, 2), res);
//     }


//     printf("%d", res);
//     return 0;
// }

//题目三 文件管理

// #define N 2000

// struct edge_type{
//     int father;
//     //指向下一个兄弟
//     int brother;
//     //指向第一个孩子
//     int child;
//     //根节点是0,
//     int level;
//     char val[10];
// } edge[N];

// int cnt = 0, n, m, vis[N];

// // add(int from, int to, char val[]){
// //     cnt++;
// //     edge[cnt].to = to;
// //     edge[cnt].next = head[from];
// //     head[from] = cnt;
// //     strcpy(edge[cnt].val, val);
// // }
// #define STACK_SIZE 50
// //栈内存的是对应层数的最后一个的edge的下标
// static int stack[STACK_SIZE];
// // static int top = -1;

// void init(){
//     memset(stack, -1, sizeof(stack));
// } 

// // int empty(){
// //     return top == -1;
// // }
// // int full(){
// //     return top == STACK_SIZE-1;
// // }

// // void pop(){
// //     assert(!empty());
// //     stack[top] = -1;
// //     top -= 1 ;
// // }
// // void push(int value){
// //     assert(!full());
// //     top += 1;
// //     stack[top] = value;
// // }

// void output(int point){
//     int father = edge[point].father;
//     if(father != 0){
//         output(father);
//     }
//     printf("/%s", edge[point].val);

// }


// int main(){
//     //初始化数组
//     init();

//     edge[0].val[0] = '/';
//     edge[0].level = 0;
//     stack[0] = 0;
//     cnt = 1;
    

//     char ch[100];
//     // int last_level = 1;

//     while(1){
//         gets(ch);
//         if(strcmp(ch, "#") == 0)break;

//         for(int i = 0; ch[i] != '\0'; i++){
//             if(ch[i] != ' '){
//                 int level = i + 1;
//                 edge[cnt].level = level;
//                 edge[cnt].father = stack[level -1];
//                 edge[cnt].child = -1;
//                 edge[cnt].brother = -1;
//                 //上一个兄弟结点指向这个
//                 //如果没有兄弟结点，就让父节点指向这个
//                 if(stack[level] != -1)edge[stack[level]].brother = cnt;
//                 else {
//                     edge[stack[level - 1]].child = cnt;
//                 }
//                 //输入文件名
//                 for(int j = 0; ch[i] != '\0'; j++, i++)edge[cnt].val[j] = ch[i];
//                 //stack操作
//                 stack[level] = cnt;

//                 cnt++;
//             }
            
//         }
//     }

//     int temp = 0;
//     char goal[10];
//     scanf("%s", goal);
//     for(int i = 1; i < cnt; i++){
//         if(strcmp(edge[i].val, goal) == 0){
//             output(i);
//             printf("\n");
//             temp++;
//         }
//     }
//     if(temp == 0)printf("NULL");

//     return n;
// }

//题目五 星际旅行

// #define N 100000
#define N 100007

void quicksort(int r[], int left, int right){
    int i = left, j = right;
    int x = r[i];
    if(i >= j)return;
    while(i < j){
        while((r[j] >= x) && (j > i))j--;
        r[i] = r[j];
        while((r[i] <= x) && (j > i))i++;
        r[j] = r[i];
    }
    r[i] = x;
    quicksort(r, left, i - 1);
    quicksort(r, i + 1, right);
    return;
}

int main(){
    int n, x[N], y[N], z[N];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
    }
    
    quicksort(x, 0, n - 1);
    quicksort(y, 0, n - 1);
    quicksort(z, 0, n - 1);

    long long res = 0, temp;
    if(n % 2 == 1){
        temp = x[(n - 1) / 2];
        for(int i = 0; i < n; i++){
            res += abs(x[i] - temp);
        }
        
        temp = y[(n - 1) / 2];
        for(int i = 0; i < n; i++){
            res += abs(y[i] - temp);
        }
        
        temp = z[(n - 1) / 2];
        for(int i = 0; i < n; i++){
            res += abs(z[i] - temp);
        }

        for(int i = 1; i <= ((n - 1) / 2); i++)res -= 2 * i;
    }
    else{   //为奇数的时候temp取中间两个及这个区间内的数字都是一样的
        temp = x[n / 2];
        for(int i = 0; i < n; i++){
            res += abs(x[i] - temp);
        }

        temp = y[n / 2];
        for(int i = 0; i < n; i++){
            res += abs(y[i] - temp);
        }

        temp = z[n / 2];
        for(int i = 0; i < n; i++){
            res += abs(z[i] - temp);
        }

        for(int i = 1; i <= (n / 2 - 1); i++)res -= 2 * i;
        res -= n / 2;
    }

    printf("%lld", res);
    return 0;
}