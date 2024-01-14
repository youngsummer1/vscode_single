#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//题目二 传信游戏

#define N 1007
int head[N], res[N], cnt = 0;
int r_cnt = 0;

struct edge_type{
    int next;
    int to;
}edge[N];

void init(){
    memset(head, -1, sizeof(head));
    // memset(visited, 0, sizeof(visited));
}

void add(int from, int to){
    cnt++;
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

void dfs(int u){
    //倒过来后，除了根0，每个点的入度必为1，所以不用设置visited[]来记录遍历情况
    for(int i = head[u]; i != -1; i = edge[i].next){
        res[r_cnt++] = edge[i].to;
        dfs(edge[i].to);
    }
}

int main(){
    init();
    int n, end;
    scanf("%d", &n);
    int temp;
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        //这里直接倒过来构建图
        add(temp, i);
    }
    
    //head[0]连的就是会收下信的人
    dfs(0);

    end = res[0];
    for(int i = 1; i < r_cnt; i++){
        end = end ^ res[i]; 
    }
    printf("%d", end);

    return 0;
}
