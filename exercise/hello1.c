#include <stdio.h>
int main()
{
    float a;
    printf("请输入数字：");
    scanf("%f",&a);
    printf("\n%f",a);
    printf("\n%d",(int)a);
    a-=(int)a;
    printf("\n%.2f",a);
    return 0;
}