#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�����������
//��u���ȫ�ֱ������߾�̬������������ȫ�������������ǲ��������Ӻ����Ľ��������پͺ�
char *Tell(void)
{
    static char u[] = "I LOVE YOU";
    return u;
}

int main()
{
    char *I = NULL;
    I = Tell();
    printf(I);
    return 0;
}