#include<stdio.h>
int func(int a, int b,int C ,int D){
    int num;
    if(a==1){
        num=C*b+D;
        return num%10;
    }
    if(a>=2)func(a-1,func(a-1,b,C,D),C,D);
}

int main(){
    int a,b,C,D;
    int num;
    scanf("%d%d%d%d",&a,&b,&C,&D);
    num=func(a,b,C,D)%10;
    printf("%d",num);
    return 0;
}