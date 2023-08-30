// 邻接表1

// 试在邻接表存储结构上实现图的基本操作 insert_vertex 和 insert_arc，相关定义如下：

// typedef int VertexType;

// typedef enum{
//     DG, UDG
// }GraphType;

// typedef struct ArcNode
// {
//     int adjvex;
//     InfoPtr *info;
//     struct ArcNode *nextarc;

// }ArcNode;

// typedef struct VNode
// {
//     VertexType data;
//     ArcNode *firstarc;
// }VNode;
// typedef struct
// {
//     VNode vertex[MAX_VERTEX_NUM];
//     int vexnum, arcnum;
//     GraphType type;
// }ListGraph;

// int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
// bool insert_vertex(ListGraph *G, VertexType v);
// bool insert_arc(ListGraph *G, VertexType v, VertexType w);
// 当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
#include <stdio.h>
#include<stdbool.h>
typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode
{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;

}ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);

bool insert_vertex(ListGraph* G, VertexType v)
{
    if (locate_vertex(G, v) != -1 || G->vexnum == MAX_VERTEX_NUM)
        return false;
    G->vertex[G->vexnum].data = v;
    G->vertex[G->vexnum].firstarc = NULL;
    G->vexnum++;
    return true;
}
bool insert_arc(ListGraph* G, VertexType v, VertexType w)
{
    if (locate_vertex(G, v) == -1 || locate_vertex(G, w) == -1)//v或者w不存在的情况
        return false;
 
    int V = locate_vertex(G, v);//v和w的下标
    int W = locate_vertex(G, w);
 
    if (G->type == 0)//有向图
    {
        ArcNode* p = G->vertex[V].firstarc;
        ArcNode* NewNodeV = (ArcNode*)malloc(sizeof(struct ArcNode));
        NewNodeV->adjvex = W;
        NewNodeV->nextarc = NULL;
        if(p != NULL)
        {
            while (p->nextarc != NULL)//遍历到当前表尾
            {
                if(p->adjvex == W)
                    return false;
                p = p->nextarc;
            }
            if(p->adjvex == W)//如果v后只连了一个节点，上面的判断就进不去，因此额外判断v后这一个节点是否为w
                return false;
            p->nextarc = NewNodeV;
        }
        else//v没有连接到任何节点
        {
            G->vertex[V].firstarc = NewNodeV;
        }
        G->arcnum ++;
    }
    else//与有向图思路一致
    {
        ArcNode* p = G->vertex[V].firstarc;
        ArcNode* q = G->vertex[W].firstarc;
        ArcNode* NewNodeV = (ArcNode*)malloc(sizeof(struct ArcNode));
        ArcNode* NewNodeW = (ArcNode*)malloc(sizeof(struct ArcNode));
        NewNodeV->adjvex = W;
        NewNodeV->nextarc = NULL;
        NewNodeW->adjvex = V;
        NewNodeW->nextarc = NULL;
        
        if(p != NULL){
            while (p->nextarc != NULL)
            {
                if(p->adjvex == W)
                    return false;
                p = p->nextarc;
            }
            if(p->adjvex == W)
                return false;
            p->nextarc = NewNodeV;
        }
        else
        {
            // if(p->adjvex == W)
            //     return false;
            G->vertex[V].firstarc = NewNodeV;
        }
        
        if(q != NULL){
            while (q->nextarc != NULL)
            {
                if(q->adjvex == V)
                    return false;
                q = q->nextarc;
            }
            if(q->adjvex == V)
                return false;
            q->nextarc = NewNodeW;
        }
        else
        {
            // if(q->adjvex == V)
            //     return false;
            G->vertex[W].firstarc = NewNodeV;
        }
        G->arcnum+=2;
    }
    return true;
}