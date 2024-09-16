#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//题目二 传信游戏

// #define N 1007
// int head[N], res[N], cnt = 0;
// int r_cnt = 0;

// struct edge_type{
//     int next;
//     int to;
// }edge[N];

// void init(){
//     memset(head, -1, sizeof(head));
//     // memset(visited, 0, sizeof(visited));
// }

// void add(int from, int to){
//     cnt++;
//     edge[cnt].to = to;
//     edge[cnt].next = head[from];
//     head[from] = cnt;
// }

// void dfs(int u){
//     //倒过来后，除了根0，每个点的入度必为1，所以不用设置visited[]来记录遍历情况
//     for(int i = head[u]; i != -1; i = edge[i].next){
//         res[r_cnt++] = edge[i].to;
//         dfs(edge[i].to);
//     }
// }

// int main(){
//     init();
//     int n, end;
//     scanf("%d", &n);
//     int temp;
//     for(int i = 1; i <= n; i++){
//         scanf("%d", &temp);
//         //这里直接倒过来构建图
//         add(temp, i);
//     }
    
//     //head[0]连的就是会收下信的人
//     dfs(0);

//     end = res[0];
//     for(int i = 1; i < r_cnt; i++){
//         end = end ^ res[i]; 
//     }
//     printf("%d", end);

//     return 0;
// }

//题目四 教数学 
int l_move(int num){
    int high = num / 10, cnt = 1, temp_1=1;
    while(high >= 10){high /= 10;cnt++;}
    for(int i = 0; i < cnt; i++)temp_1 *= 10;
    num -= temp_1;
    num += high;
    return num;
}

int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

int main(){
    int left, right;
    scanf("%d", &left);
    scanf("%d", &right);

    int high = left / 10, cnt = 2, count = 0;
    while(high >= 10){high /= 10;cnt++;}

    while(count != cnt){
        if(gcd(left,right) == 1)break;
        count++;
        left = l_move(left);
        right = l_move(right);
    }
    if(count == cnt)printf("-1");
    else printf("%d", count);
    return 0;
}


//题目五 地狱尖兵
// #define StackSize 20

// typedef struct{
//     char data[StackSize];
//     int front, rear;
// } SeqQueue;

// void InitQueue(SeqQueue *q){
//     q = (SeqQueue *)malloc(sizeof(SeqQueue));
//     q->front = q->rear = -1;
// }

// void ClearQueue(SeqQueue *q){
//     q->front = -1;
//     q->rear = -1;
// }

// int QueueEmpty(SeqQueue *q){
//     return (q->front == q->rear);
// }

// int EnterQueue(SeqQueue *q, )