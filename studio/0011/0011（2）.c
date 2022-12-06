#include<stdio.h>
//出错原因：
//指针mid未初始化（没有给它分配地址），那么它指向的地址就是随机的，是系统分配给它的，同时也是非法的，不能使用
//解决方法：
//直接把int* mid改成int mid来储存*b
void swap(int* a, int* b) {
    int mid;
    mid = *b;
    *b = *a;
    *a = mid;
}
int main() {
    int num1, num2;
    printf("please input the two nums:\n");
    scanf("%d %d", &num1, &num2);
    printf("num1 is %d,num2 is %d\n", num1, num2);
    swap(&num1, &num2);
    printf("num1 is %d,num2 is %d\n", num1, num2);
    return 0;
}