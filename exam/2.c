#include<stdlib.h>
#include<stdio.h>
#include<math.h>
// int main(){
//     int a[20],num,i,sum=0;
//     scanf("%d",&num);
//     for(i=0;num>1;i++){

//         if(num%2==1)
//             a[i]=1;
//         if(num%2==0)
//             a[i]=0;
//         num=num/2;
//     }
//     a[i]=num;

//     int k=1;
//     while(k<=i){
//         if(a[k]==1)a[k]=0;
//         k+=2;
//     }
//     k=i;
//     while(k>0){
//         sum=(sum+a[k])*2;
//         k--;
//     }
//     sum+=a[k];
//     printf("%d",sum);
//     return 0;


// }

// int main(){
//     int num,i=1;
//     scanf("%d",&num);
//     for(i=1;i*i<=num;i=i+2){
//         printf("%d\n",i*i);
//     }
//     return 0;

// }
// int max(int n,int h[]){

// }
// int* max_num(int n,int h[][10],int carry[][10],int max_xy[2]){
//     max_xy[0]=max_xy[1]=0;
//     for(int i=0;i<n;i++){
//         for(int k=0;k<n;k++){
//             if(h[i][k]!=0&&carry[i][k]==0){
//                 if(h[i][k]>h[max_xy[0]][max_xy[1]]||carry[max_xy[0]][max_xy[1]]==1){
//                     max_xy[0]=i;
//                     max_xy[1]=k;
//                 }
//             }
//         }
//     }
// }
// int check(int n,int h[][10],int carry[][10],int x,int y,int a,int b){
//     if(h[x][y]==0||h[x][y]>=h[a][b]||x<0||x>10||y<0||y>10)return;
//     else{
//         carry[x][y]=1;
//         if(carry[x+1][y]==0)check(n,h,carry,x+1,y,x,y);
//         if(carry[x-1][y]==0)check(n,h,carry,x-1,y,x,y);
//         if(carry[x][y+1]==0)check(n,h,carry,x,y+1,x,y);
//         if(carry[x][y-1]==0)check(n,h,carry,x,y-1,x,y);

//     }
// }
// int check_main(int n,int h[][10],int carry[][10],int x,int y){
//     carry[x][y]=1;
//     if(carry[x+1][y]==0)check(n,h,carry,x+1,y,x,y);
//     if(carry[x-1][y]==0)check(n,h,carry,x-1,y,x,y);
//     if(carry[x][y+1]==0)check(n,h,carry,x,y+1,x,y);
//     if(carry[x][y-1]==0)check(n,h,carry,x,y-1,x,y);
// }
// int main(){
//     int n,h[10][10],carry[10][10],count=0;
//     scanf("%d",&n);
//     for(int i=0;i<10;i++){
//         for(int k=0;k<10;k++){
//             if(i<n&&k<n)scanf("%d",&h[i][k]);
//             else {h[i][k]=0;}
//             carry[i][k]=0;
//         }
//     }
//     int xy[2];
//     max_num(n,h,carry,xy);
//     while(carry[xy[0]][xy[1]]==0){
//         count++;
//         check_main(n,h,carry,xy[0],xy[1]);
//         max_num(n,h,carry,xy);
//     }
//     printf("%d",count);

//     return 0;
// }
// int test(int a[]){
//     a[0]=20;
// }
// int main(){
//     int a[2];
//     a[0]=3;
//     a[1]=5;
//     test(a);
//     printf("%d",a[0]);

//     return 0;
// }

// int main(){
//     int n,a[500],num[1000],k;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//     }
//     for(int i=0;i<n;i++){
//         if(a[i]%2==0)printf("NO\n");
//         else if(a[i]%2==1){
//             printf("YES\n");
//             int max=a[i]+1,min=max/2;
//             for(k=0;k<a[i];k++){
//                 printf("%d %d ",max,min);
//                 max+=2,min-=1;
//                 if(min<=0){
//                     max=a[i]+2,min=a[i];
//                 }
//             }
//             printf("\n");
//         }
//     }
//     return 0;
// }

// int main(){
//     int n,a[10],b[10],sum;
//     scanf("%d %d",&n,&sum);
//     sum=-(sum/2);
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//         scanf("%d",&b[i]);
//     } 
//     for(int i=0;i<n;i++){
//         sum+=a[i]*50;
//         if(sum>0){
//             sum-=b[i]/2;
//         }
//     }
//     printf("%d",sum);
//     return 0;
// }
// #define N 1e4+7
#define N 3000

int main(){
    // int a=2,b;
    // b=pow(a,5);
    // printf("%d",b);
    printf("%d",N);
    return 0;
}
