#include<stdio.h>
// int main(){
//     int num;
//     int i=0,k=0,s=0,number_num=0;
//     scanf("%d",&num);
//     for(i=1;k<=num;i++){
//         k=i;
//         while(k!=0){
//             s=s*10+k%10;
//             k=k/10;
//         }
//         if(i%s==0)number_num++;
//     }
//     printf("%d",number_num);
//     return 0;
// }


int main() 
{ 
    int num;
    int number_num=0,s;
    int i=1;
    scanf("%d",&num);

    for(i=1;i<=num;i++){
        int a=i;
        s=0;
        while(a!=0){
            s=s*10+a%10;
            a=a/10;

        }
        if(i%s==0)number_num++;
    }
    printf("%d",number_num);
    return 0; 
}
