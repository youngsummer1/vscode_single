// 堆初始化

// 二叉堆一般用数组来表示。例如，根节点在数组中的位置是0，第n个位置的子节点分别在2n+1和 2n+2。 因此，第0个位置的子节点在1和2，1的子节点在3和4。以此类推。这种存储方式便于寻找父节点和子节点。在二叉堆上可以进行插入节点、删除节点、取出值最小的节点、减小节点的值等基本操作。

// “最小堆”的定义如下：

// typedef struct _otherInfo
// {
//     int i;
//     int j;
// }OtherInfo;

// typedef struct _minHeapNode
// {
//     int value;
//     OtherInfo otherInfo;
// }MinHeapNode, *PMinHeapNode;

// typedef struct _minPQ {
//     PMinHeapNode heap_array; // 指向堆元素数组
//     int heap_size; // 当前堆中的元素个数
//     int capacity;  //堆数组的大小
// }MinHeap, *PMinHeap;
// 请实现最小堆的初始化函数：

// void init_min_heap(PMinHeap pq, int capacity);
// 其中 pq指向堆，capacity为堆元素数组的初始化大小。


#include <stdio.h>
#include <stdlib.h>

typedef struct _otherInfo
{
    int i;
    int j;
}OtherInfo;

typedef struct _minHeapNode
{
    int value;
    OtherInfo otherInfo;
}MinHeapNode, *PMinHeapNode;

typedef struct _minPQ {
    PMinHeapNode heap_array; // 指向堆元素数组
    int heap_size; // 当前堆中的元素个数
    int capacity;  //堆数组的大小
}MinHeap, *PMinHeap;
void init_min_heap(PMinHeap pq, int capacity);


//pq指向堆,capacity为堆元素数组的初始化大小
void init_min_heap(PMinHeap pq, int capacity){
 pq->capacity = capacity;
 pq->heap_size = 0;
 pq->heap_array = (PMinHeapNode)malloc(sizeof(MinHeapNode) * pq->capacity);
 return;
}