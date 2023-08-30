// 邻接矩阵

// 试在邻接矩阵存储结构上实现图的基本操作 matrix_insert_vertex 和matrix_insert_arc，相关定义如下：

// typedef int VertexType;

// typedef enum{
//     DG, UDG
// }GraphType;

// typedef struct{
//     VertexType vertex[MAX_VERTEX_NUM]; //顶点向量
//     int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
//     int vexnum, arcnum;   //图的当前顶点数和弧数
//     GraphType type;     //图的种类标志
// }MatrixGraph;

// int matrix_locate_vertex(MatrixGraph *MG, VertexType vex); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
// bool matrix_insert_vertex(MatrixGraph *G, VertexType v);
// bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w);
// 当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。

#include <stdio.h>
// #include "graph.h" // 请不要删除，否则检查不通过
#include<stdbool.h>

typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct{
    VertexType vertex[MAX_VERTEX_NUM]; //顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum;   //图的当前顶点数和弧数
    GraphType type;     //图的种类标志
}MatrixGraph;
int matrix_locate_vertex(MatrixGraph *MG, VertexType vex); //返回顶点 v 
bool matrix_insert_vertex(MatrixGraph *G, VertexType v);
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w);

bool matrix_insert_vertex(MatrixGraph *G, VertexType v){
	int i;
	i = matrix_locate_vertex(G, v);
	if(i == -1 && G->vexnum < MAX_VERTEX_NUM - 1){
		G->vertex[G->vexnum++] = v;
		for(i = 0; i < G->vexnum; i++){
			G->arcs[i][G->vexnum -1] = 0;
			G->arcs[G->vexnum-1][i] = 0;
		}
		return true;
	}
	return false;
}
 
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w){
	int i, j;
	i = matrix_locate_vertex(G, v);
	j = matrix_locate_vertex(G, w);
	if(i == -1 || j == -1) return false;
	if(G->type == UDG &&( G->arcs[i][j] == 1 || G->arcs[j][i] == 1))
		return false;
	else if(G->arcs[i][j] == 1)	
		return false;
	
	if(G->type == UDG)
		G->arcs[j][i] = 1;
	G->arcs[i][j] = 1;
	G->arcnum++;
	return true;
}