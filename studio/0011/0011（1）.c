#include <string.h>
#include <stdio.h>
#include <malloc.h>

//������ԭ��:free()֮����Ҫ��ָ���ÿ�
//��Ϊfree�������ǽ�ָ�����������ָ�Ŀռ�Ĺ�ϵն�ϣ��޷�ͨ��ָ������ǿ�ռ䣩
//��ʵ����ָ�뱾����ĵ�ַ��û�иı䣬���ͷŵ��ǿ��ڴ����汣���ֵҲû�иı�
//�������ָ���ÿգ���ʹ����Ұָ�룬ʮ��Σ��
int main()
{
    char *p = (char *)malloc(100);
    strcpy(p, "nihao");
    free(p);    
    p=NULL;      
    if (p != NULL)         
        strcpy(p, "shijie");
    for (int i = 0; i < 6; i++)
        printf("%c", *(p + i));
    printf("\n");
    return 0;
}