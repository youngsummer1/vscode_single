// 堆元素插入

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
// 请实现最小堆的元素插入函数：

// bool heap_insert_value(PMinHeap pq, int value);
// 其中 pq指向堆，value 为要插入的堆元素。

// （注：假设辅助函数 parent 和 swap_node 已正确实现，heap_insert_value 函数可直接使用。）
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
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

bool heap_insert_value(PMinHeap pq, int value);


//parent 和 swap_node 已正确实现,pq指向堆，value 为要插入的堆元素
bool heap_insert_value(PMinHeap pq, int value){
	//如果满了，就无法插入
	if (pq->heap_size == pq->capacity)return false;
 
	int i = pq->heap_size;
	int j;
	int temp;
 
	//p指向根节点
	MinHeapNode* p = pq->heap_array;
 
	//插入最后一位
	p[i].value = value;
	pq->heap_size++;
 
	while (1) {
		j = parent(i);
		//j不是节点的父亲
		if (p[i].value <= p[j].value) {
			temp = p[i].value;
			p[i].value = p[j].value;
			p[j].value = temp;
			i = j;
			if (i == 0)return true;
		}
		else return true;
	}
}