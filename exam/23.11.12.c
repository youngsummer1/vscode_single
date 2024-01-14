#include<stdio.h>
#include<string.h>

//题目一 跑图

// #define N 100

// struct edge_type{
//     int next;
//     int val;
//     int to;
// } edge[N];

// int head[N], cnt = 0, n , m;

// void init(){
//     memset(head, -1, sizeof(head));
// }

// int add(int from, int to, int val){
//     cnt++;
//     edge[cnt].val = val;
//     edge[cnt].to = to;
//     edge[cnt].next = head[from];
//     head[from] = cnt;
// }

// int main(){
//     init();

//     scanf("%d %d", &n, &m);
//     for(int i = 0; i < m; i++){
//         int from, to, val;
//         scanf("%d %d %d", &from, &to, &val);
//         add(from, to, val);
//     }

//     for(int i = 1; i <= n; i++){
//         int val = 0, to;
//         int position = head[i];

//         if(position == -1){
//             printf("%d\n", val);
//             continue;
//         }

//         while(position != -1){
//             if(val < edge[position].val){
//                 val = edge[position].val;
//                 to = edge[position].to;
//             }
//             position = edge[position].next;
//         }
//         printf("%d %d\n", to, val);
//     }


//     return 0;
// }


//题目二 跑图
//有两个案例没过，暂时没找出原因
// #define N 100

// struct edge_type{
//     int next;
//     int val;
//     int to;
// } edge[N];

// int head[N], cnt = 0, n , m, visited[N];

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

// int main(){
//     init();

//     scanf("%d %d", &n, &m);
//     for(int i = 0; i < m; i++){
//         int from, to, val;
//         scanf("%d %d %d", &from, &to, &val);
//         add(from, to, val);
//     }

//     int pos = 1;
//     if(head[pos] == -1)printf("none");

//     while(1){
//         if(head[pos] == -1 )break;
//         visited[pos] = 1;
//         int to , val = 0, temp = head[pos];
//         while(temp != -1){
//             if(val < edge[temp].val){
//                 to = edge[temp].to;
//                 val = edge[temp].val;
//             }
//             temp = edge[temp].next;
//         }
//         if(visited[to])break;
//         printf("%d %d\n", to, val);

//         pos = to;
//     }


//     return 0;
// }


//题目三 跑图
#define N 100

struct edge_type{
    int next;
    int val;
    int to;
} edge[N];

int head[N], cnt = 0, n , m;

void init(){
    memset(head, -1, sizeof(head));
}

int add(int from, int to, int val){
    cnt++;
    edge[cnt].val = val;
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

void quicksort(struct edge_type edge_res[], int left,int right){
    int i = left, j = right;
    int x = edge_res[i].to, val = edge_res[i].val;
    struct edge_type temp = edge_res[i];

    if(i >= j)return;
    while(i < j){
        while((edge_res[j].to >= x) && (j > i)){
            if(edge_res[j].to == x && edge_res[j].val < val)break;
            j--;
        }
        edge_res[i] = edge_res[j];

        while((edge_res[i].to <= x) && (j > i)){
            if(edge_res[i].to == x && edge_res[i].val > val)break;
            i++;
        }
        edge_res[j] = edge_res[i];
    }
    edge_res[i] = temp;
    quicksort(edge_res,left,i-1);
    quicksort(edge_res,i+1,right);
    return;
}

int main(){
    init();

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
        add(from, to, val);
    }

    int pos_max = 1, len_max = 0;
    for(int i = 1; i <= n; i++){
        int len_temp = 0, pos = head[i];
        while(pos != -1){
            len_temp++;
            pos = edge[pos].next;
        }
        if(len_max < len_temp){
            len_max = len_temp;
            pos_max = i;
        }
    }

    int pos = head[pos_max], i = 0;
    struct edge_type edge_res[N];
    for(i = 0; pos != -1; i++){
        edge_res[i].val = edge[pos].val;
        edge_res[i].to = edge[pos].to; 
        pos = edge[pos].next;
    }
    quicksort(edge_res, 0 , i-1);

    printf("%d\n", pos_max);
    for(int j = 0; j < i; j++){
        printf("%d %d\n",edge_res[j].to, edge_res[j].val);
    }
    return 0;
}