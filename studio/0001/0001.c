#define _CRT_SECURE_NO_WARNINGS ��
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// ������Ŀ������B���Ŵ�A������
//1.û������stdlib.h��malloc��ͷ�ļ���malloc.hҲ�У�(�����Ȼ������õģ�ֱ����mallocʱ�ŷ��ֺ���ԭ�Ͳ��Ծ�)
//2.strlenֻ�����ַ��������ݣ�����\0������������length=10
//��˸�B���ٿռ��ʱ��Ҫ��length+1����srcָ��A�����һ���ַ�ʱӦ����length-1��Ҫ��Ȼ���Ƶ�\0�ᵼ��B�ĵ�һ���ַ�����\0�����´�ӡ��������
//3.��B�����ϸ�\0����ֹ��Ҫ��Ȼ��������������ֱ������\0��
//��Ӧ�þ���Щ�˰�....��
int main()
{
    char* A = "I LOVE YOU";
    char* B = NULL;
    int length = strlen(A);

    B = (char*)malloc(length+1);

    char* dest = B;

    char* src = &A[length-1];

    while (length-- != 0)
        *dest++ = *src--;
    *dest = '\0';
    printf("%s", B);
    return 0;
}