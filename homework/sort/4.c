// 堆化

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
// 请实现最小堆的“堆化”函数：

// void min_heapify(PMinHeap pq, int i);
// 其中 pq指向堆，i 为堆元素在数组中的下标。该函数假设元素i对应的子树都已经是最小堆（符合最小堆的要求），但元素i为根的子树并不是最小堆，min_heapify将对元素i及其子树的各结点进行调整，使其为一个最小堆。

// （注：假设辅助函数 left、right、parent 和 swap_node 已正确实现，min_heapify 函数可直接使用。）
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
void min_heapify(PMinHeap pq, int i);

void min_heapify(PMinHeap pq, int i){
	int j = 2 * i + 1;
	MinHeapNode* p = pq->heap_array;
	while (j <= pq->heap_size - 1){
		//j为最小值的堆
		if (p[j + 1].value < p[j].value)
			j = j + 1;
		if (p[j].value < p[i].value) {
			swap_node(&p[j], &p[i]);
			i = j;
			j = 2 * i + 1;
		}
		else return;
	}
}