#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//��������
//��Tell�д�����ʱ��ָ�룬Ϊ������ռ䣬Ȼ�󷵻����ָ��
char* Tell()
{
    char* U = (char *)malloc(100);
    if(NULL==U){//����Ƿ����ɹ�
        printf("����ʧ��");
        exit(1);
    }
    memset(U,'\0',100);//����ڴ�ռ�
    return U;
}
int main()
{
    char *I = NULL;
    I=Tell();
    strcpy(I, "I LOVE YOU");
    printf(I);
    free(I);//���ɺ�ϰ�߼�ʱfree
    I=NULL;
    return 0;
}