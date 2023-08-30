#include<stdio.h>
int main() 
{ 
    int F;
    float C;
    scanf("%d",&F);
    C=9*(F-32)/5.0;
    printf("%.6f",C);
    return 0; 
}