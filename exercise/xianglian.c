#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[],int left,int right){
    int i=left,j=right;
    int x=a[i];
    if(i>=j)return;
    while(i<j){
        while((a[j]>=x)&&(j>i))j--;
        a[i]=a[j];
        while((a[i]<=x)&&(j>i))i++;
        a[j]=a[i];
    }
    a[i]=x;
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
    return;
}
// int main(){
//     int num;
//     int max,min;
//     int temp;
//     int b[100],a[100];
//     int beautiful;
//     scanf("%d",&num);
//     for(int i=0;i<num;i++)scanf("%d",&a[i]);
//     quicksort(a,0,num-1);
//     for(int i=0,j=num-1,k=0;i<=j;i++,j--){
//         if(i==j){
//             b[k]=a[i];
//             break;
//         }
//         b[k++]=a[j];
//         b[k++]=a[i];
//     }
//     // for(int i=0;i<num;i++){
//     //     max=min=i;
//     //     for(int k=i+1;k<num;k++){
            
//     //         if(i%2==0&&a[k]>a[max])max=k;
//     //         if(i%2==1&&a[k]<a[min])min=k;
//     //     }
//     //     if(i%2==0){
//     //         temp=a[max];
//     //         a[max]=a[i];
//     //         a[i]=temp;
//     //     }
//     //     if(i%2==1){
//     //         temp=a[min];
//     //         a[min]=a[i];
//     //         a[i]=temp;
//     //     }
//     // }
//     b[num]=b[0];
//     for(int i=0;i<num;i++){
//         beautiful+=abs(b[i]-b[5+1]);
//     }
//     printf("%d",beautiful);
//     return 0;
// }

int main(){
    int num;
    int max,min;
    int temp;
    int a[100];
    int beautiful;
    scanf("%d",&num);
    for(int i=0;i<num;i++)scanf("%d",&a[i]);
    quicksort(a,0,num-1);
    for(int i=0;i<num;i++){
        beautiful+=abs(a[i]-a[num-1-i]);
    }
    printf("%d",beautiful);
    return 0;
}
