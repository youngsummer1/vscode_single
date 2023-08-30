// 邻接表2

// 试在邻接表存储结构上实现图的基本操作 del_vertex，相关定义如下：

// typedef int VertexType;

// typedef enum{
//     DG, UDG
// }GraphType;

// typedef struct ArcNode{
//     int adjvex;
//     InfoPtr *info;
//     struct ArcNode *nextarc;
// }ArcNode;

// typedef struct VNode{
//     VertexType data;
//     ArcNode *firstarc;
// }VNode;
// typedef struct{
//     VNode vertex[MAX_VERTEX_NUM];
//     int vexnum, arcnum;
//     GraphType type;
// }ListGraph;

// int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
// bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v
// 当成功删除顶点或边时，函数返回true，否则（如顶点或边不存在、删除边时顶点v或w不存在）返回false

#include <stdio.h>
#include<stdbool.h>

typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v