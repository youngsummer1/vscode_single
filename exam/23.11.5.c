#include<stdio.h>



//题目一 枚举方案
int visited[30] , path[30];
void FindPath_DFS(int n, int now, int length, int goal){
    length++;
    path[length] = now;
    visited[now] = 1;

    //输出
    if(length == goal){
        for(int i = 1; i <= length; i++)printf("%d ",path[i]);
        printf("\n");
    }

    now = (now == n)? 1 : now + 1;
    while(){
        
    }

}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; i++)visited[i] = 1;
    int now = 0, length = 0;



}