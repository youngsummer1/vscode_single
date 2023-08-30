// 数组合并

// 假设有 n 个长度为 k 的已排好序（升序）的数组，请设计数据结构和算法，将这 n 个数组合并到一个数组，且各元素按升序排列。即实现函数：

//  void merge_arrays(const int* arr, int n, int k, int* output);
// 其中 arr 为按行优先保存的 n 个长度都为 k 的数组，output 为合并后的按升序排列的数组，大小为 n×k。

// 时间要求(评分规则)，当 n > k 时：

// 满分：时间复杂度不超过 O(n×k×log(n))
// 75分：时间复杂度不超过 O(n×k×log(n)×k)
// 59分：其它，如：时间复杂度为 O(n2×k2) 时。

#include<stdio.h>

 void merge_arrays(const int* arr, int n, int k, int* output);

 void max_heapify(int* p, int i, int size) {
 
    int j = 2 * i + 1, t=p[i];
    while (j <= size - 1) {
        if (j + 1 <= size - 1 && p[j] < p[j + 1])j = j + 1;
        if (p[j] > t) {
 
            p[i] = p[j];
            i = j;
            j = 2 * i + 1;
        }
        else break;
    }
    p[i] = t;
}//假设i之后都是大根堆，调整i使从i开始都是大根堆
 
 
void merge_arrays(const int* arr, int n,int k,int* output) {
    int size=n*k;
    int x, i, *array;
    array = (int*)malloc(size * sizeof(int));
    
    for (i = 0; i <= size - 1; i++) {
        array[i] = arr[i];
    }
 
     for (i=size/2-1; i >=0 ; i--) {
        max_heapify(array, i, size);
    }//将整个堆大根堆化
    for (i = size-1; i >= 1; --i) {
        x = array[0];
        array[0] = array[i];
        array[i] = x;
        max_heapify(array, 0, i);
    }
    for (i = 0; i <= size - 1; i++) {
        output[i] = array[i];
    }
 
}