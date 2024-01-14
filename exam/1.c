#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// int main() 
// { 
//     int rol,col;
//     scanf("%d %d",&rol,&col);
//     int num,manhattan;
//     manhattan=abs(rol)+abs(col);
//     for(int i=1;i<=manhattan;i++){
//         num+=4*i-4;
//     }
//     if(rol>0&&col>=0)num+=rol;
//     if(rol>=0&&col<0)num+=manhattan+abs(col);
//     if(rol<0&&col<=0)num+=manhattan*2+abs(rol);
//     if(rol<=0&&col>0)num+=manhattan*3+abs(col);
//     printf("%d",num);
//     return 0; 
// }


// int main(){
//     int n,a[100],b[100],c[100];
//     scanf("%d",&n);
//     for(int i=0;i<n;i++)scanf("%d",&a[i]);
//     for(int i=0;i<n;i++)scanf("%d",&b[i]);
    
//     int min,num,temp;
//     for(int i=0;i<n;i++){
//         min=(a[i]+b[i])%n;
//         num=i;
//         for(int k=i+1;k<n;k++){
//             if(min==0)break;
//             if(min>(a[i]+b[k])%n){
//                 min=(a[i]+b[k])%n;
//                 num=k;
//             }
//         }
//         temp=b[i];
//         b[i]=b[num];
//         b[num]=temp;
//         c[i]=min;
//     }
//     for(int i=0;i<n;i++)printf("%d ",c[i]);
//     return 0;
// }
#define max 5555555
struct hash_tabel{
    int key;
    int num;
};
int main(){
    int n,a[100],hash_number=23,hash_num;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int num,q;
    struct hash_tabel hash[23];
    for(int i=0;i<hash_number;i++){
        hash[i].key=max;
        hash[i].num=0;
    }
    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            for(q=i;q<=k;q++)num+=a[q];
                    num=abs(num);
                    hash_num=num%hash_number;
                if(hash[hash_num].key==max){
                    hash[hash_num].num++;
                    hash[hash_num].key=num;
                }
                if(hash[hash_num].key==num)hash[hash_num].num++;
                else{
                    for(int h=1;h<hash_number;h++){
                        if(hash[(hash_num+h)%hash_number].key==max){
                            hash[hash_num].num++;
                            hash[hash_num].key=num;
                        }
                if(hash[(hash_num+h)%hash_number].key==num)hash[(hash_num+h)%hash_number].num++;
                    }
                }
        }

    }
    int MAX=0;
    for(int i=1;i<hash_number;i++){
        if(hash[MAX].num<hash[i].num){
            MAX=i;
            continue;
        }
        if(hash[MAX].num==hash[i].num&&hash[MAX].key>hash[i].key)MAX=i;
    }
    printf("%d %d",hash[MAX].num,hash[MAX].key);
    return 0;
}