#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//����ԭ��
//Tell�����������������ˣ���Ȼ����Ŀռ仹�ڣ���Ϊmalloc���ڶѣ�heap��������ģ����Բ�����Ϊ���������ٶ����٣�Ҫ����Ա������free���У�����I����ָ���ǿ�ռ�
//����һ
//����I�ĵ�ַ���ö���ָ�����ı�ָ��
//������Ҫ���ð�ȫ������ ���ɺõ�ϰ�ߡ̣�������ռ���������ռ��е����ݣ�����malloc��free��÷���һ�������б������ǣ�
void Tell(char **U)
{
    *U = (char *)malloc(100);
    if(NULL==*U){//����Ƿ����ɹ�
        printf("����ʧ��");
        exit(1);
    }
    memset(*U,'\0',100);//����ڴ�ռ�
}
int main()
{
    char *I = NULL;
    Tell(&I);
    strcpy(I, "I LOVE YOU");
    printf(I);
    free(I);//���ɺ�ϰ�߼�ʱfree
    I=NULL;
    return 0;
}