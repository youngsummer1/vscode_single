#include<stdio.h>
#include<math.h>
// #include<iostream>
// #include<cstring>
// #include<algorithm>
// using namespace std;

// int f[10000];
// int main(){
//     int n,x,c[100];
//     scanf("%d %d",&n,&x);
//     for(int i=1;i<=n;i++){
//         scanf("%d",&c[i]);
//         c[i]=c[i]*(n-i+1);
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=x;j>=c[i];j--){
//             f[j]=fmax(f[j],f[j-c[i]]+1);
//         }
//     }
//     printf("%d",f[x]);


//     return 0;
// }


// int f[10000];
// int main(){
//     int n,T,v[100],c[100],path[100][100];
//     scanf("%d %d",&n,&T);
//     for(int i=1;i<=n;i++){
//         scanf("%d %d",&v[i],&c[i]);
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=T;j>=c[i];j--){
//             if(f[j-c[i]]+v[i]>f[j]){
//                 f[j]=f[j-c[i]]+v[i];
//                 path[i][j]=1;
//             }
//         }
//     }
//     printf("%d\n",f[T]);
//     int i=n,j=T,plan[100],num=0;
//     while(i>=1&&j>=1){
//         if(path[i][j]!=0){
//             plan[num++]=i;
//             j=j-c[i];
//         }
//         i--;
//     }
//     for(int k=num-1;k>=0;k--)printf("%d ",plan[k]);

//     return 0;
// }


// int f[10000];
// int n,T,v[100],c[100],path[100][100];
// int main(){

//     scanf("%d %d",&n,&T);
//     for(int i=1;i<=n;i++)
//         scanf("%d %d",&v[i],&c[i]);
    
//     for(int i=1;i<=n;i++){
//         for(int j=T;j>=c[i];j--){
//             if(f[j-c[i]]+v[i]>f[j]){
//                 f[j]=f[j-c[i]]+v[i];
//                 path[i][j]=1;
//             }
//         }
//     }
//     printf("%d\n",f[T]);
//     int i=n,j=T,plan[100],num=0;
//     while(i>=1&&j>=1){
//         if(path[i][j]!=0){
//             plan[num++]=i;
//             j=j-c[i];
//         }
//         i--;
//     }
//     for(int k=num-1;k>=0;k--)printf("%d ",plan[k]);

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// int a[10005],b[10005],t=0,k=0,n,m,dp[10005]={ },w,v,s,path[10005][10005]={0},res[10005];
// int main(){
//     cin>>n>>m;
//     while(n--){
//         cin>>w>>v;
//         a[++t]=v;
//         b[t]=w;}
//     for(int i=1;i<=t;i++){
//         for(int j=m;j>=a[i];j--){
//             if(dp[j-a[i]]+b[i] > dp[j]){
//                 dp[j] = dp[j-a[i]]+b[i];
//                 path[i][j] = 1;}}
//                 }
//     cout<<dp[m]<<endl;
//     int i = t, j = m;
//     while(i > 0 && j > 0){
//         if(path[i][j] == 1){
//             res[k]=i;k++;j -= a[i];
//             }
//         i--;}
//     for(i=k-1;i>=0;i--){cout<<res[i]<<' ';}
//     return 0;}




int f[550][550];
int n,m,b,mod,a[550];
int main(){

    scanf("%d %d %d %d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=a[i];k<=b;k++){
                f[j][k] = (f[j][k]+f[j-1][k-a[i]])%mod;
            }
        }
    }
    int plan_num;
    for(int k=0;k<=b;k++){
        plan_num=(plan_num+f[m][k])%mod;
    }
    printf("%d",plan_num);
    return 0;
}