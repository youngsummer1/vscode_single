#include<stdio.h>
//����ԭ��
//ָ��midδ��ʼ����û�и��������ַ������ô��ָ��ĵ�ַ��������ģ���ϵͳ��������ģ�ͬʱҲ�ǷǷ��ģ�����ʹ��
//���������
//ֱ�Ӱ�int* mid�ĳ�int mid������*b
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