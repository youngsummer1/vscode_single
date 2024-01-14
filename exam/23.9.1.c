#include<stdio.h>
#include<string.h>


// int c=10000007;
// long divide_1(long a, long b) {
// 		if (b == 0)
// 			return 1;
// 		else if (b % 2 == 0) //偶数情况
// 			return divide_1((a % c) * (a % c), b / 2) %c;
//     else//奇数情况
// 			return a % c * divide_1((a % c) * (a % c), (b - 1) / 2) %c;
// 			//注意每次返回的是什么
// 	}


// long divide_2(long a, long b) {
//   a %= c;
//   long res = 1;
//   for (; b != 0; b /= 2) {
//     if (b % 2 == 1)
//       res = (res * a) % c;
// 	  //这里res*a而不需要各自取模，因为原来的res已经在上一个循环取过模
// 	  //res%c*a%c
//     a = (a * a) % c;
//   }
//   //很妙，每次循环幂的次数减半，同时底数a翻倍
//   return res;
// }
// int main(){
//   long a=2,b=29;
//   printf("%ld\n",divide_1(a,b));
//   printf("%ld",divide_2(a,b));

//   return 0;
// }

//题目1 Good Num 的数量
//快速幂
// long long p = 1000000007;

// long long divide_2(long long a, long long b){
//   a %= p;
//   long long result = 1;
//   for(; b != 0; b /= 2){
//     if(b % 2 == 1 )result = (result * a) % p;
//     a = (a * a) % p; 
//   }
//   return result;

// }



// int main(){
//   long long k, result_odd, result_even, result;
//   scanf("%lld",&k);
  
//   result_odd = divide_2(4, k/2);
//   if(k % 2 == 1 ){
//     result_even = divide_2(5, k/2 + 1);
//   }
//   else result_even = divide_2(5, k/2);

//   result = (result_even*result_odd)%p;
//   printf("%lld", result);
//   return 0;
// }

//题目2 幂和

// long long p = 998244353;

// long long divide_1(long long a , long long b){
//   a %= p;
//   long long result = 1;
//   for(; b != 0; b /= 2 ){
//     if(b % 2 == 1 ){
//       result = (result * a) %p ;
//     }
//     a = (a * a) %p ;
//   }
//   return result;

// }

// int main(){
//   int n;
//   long long result;

//   scanf("%d",&n);
//   for(int i = 1; i <= n; i++){
//     result = (result + divide_1(i,i)) % p;
//   }
//   printf("%lld",result);

//   return 0;
// }


//题目5 快速幂

// long long divide_3(long long a, long long b, long long c){
//   if(b == 0)return 1;
//   long long temp ;
//   if(b % 2 == 0){
//     temp = divide_3((a%c)*(a%c), b/2, c);
//     return temp %c;
//   }
//   else{
//     temp = divide_3((a%c)*(a%c), (b-1)/2, c);
//     return a%c * temp %c;
//   }
// }

// int main(){
//   long long a,b,c, result;
//   scanf("%lld %lld %lld",&a,&b,&c);

//   result = divide_3(a, b, c);
//   printf("%lld",result);


//   return 0;
// }


//题目6 进行一个幂的运算
// long long c = 100000007;
// long long divide_4(long long a, long long b){
//   a %= c;
//   long long q=2, power = 1, result = 1;

//   for(; b != 0; b /= 2){
//     if(b % 2 == 1)power *= q;
//     q *= q ;
//   }
//   power --;

//   for(; power != 0; power /= 2){
//     if(power % 2 == 1)
//       result = (result * a) % c;
//     a = (a * a) % c;
//   }
//   return result;
// }

// long long power_1(long long a, long long b){
//   long long result = 1;
//   for(; b != 0; b /= 2){
//     if(b % 2 == 1)result *= a;
//     a *= a;
//   }
//   return result;
// }
// int main(){
//   long long m , k ,result  ;
//   scanf("%lld %lld",&m ,&k );
//   // power = power_1(2,k) - 1;
//   result = divide_4(m,k);
//   printf("%lld",result);
 


//   return 0;
// }


//题目3 个数统计

//数字位数
void setLen(int a[], int i){
  while(a[i] == 0 && i>1){
    i--;
  }
  a[0] = i;
}

void Multiply(int a[], int b){
  int c = 0, i;
  for(i = 1; i <= a[0]; i++){
    a[i] = a[i] * b + c;
    c = a[i] / 10;
    a[i] %= 10;
  }
  while(c > 0){
    a[i] = c % 10;
    c /= 10 ;
    i++;
  }
  setLen(a , i);

}

// #define N 3000
// int main(){
//   int num[N] = {0};
//   int n , a, count = 0;
//   scanf("%d %d",&n ,&a);
//   num[1] = 1;
//   setLen(num ,1);
//   for(int i=2 ; i <= n; i++){
//     Multiply(num ,i);
//   }
//   for(int i=1; i <= num[0]; i++){
//     if(num[i] == a)count++;
//   }
//   printf("%d",count);
// }


//题目4 个体统计2
#define N 3000
int find_num(int a[], int b[], int pos){
  int i = 0;
  if(pos < b[0])return 0;
  while(a[pos-i] == b[b[0]-i] && i < b[0]){
    if(a[pos - i] != b[b[0] - i])break;
    i++;
    if(i == b[0])return 1;
  }
  return 0;
}



int main(){
  int n, count = 0 ,b[N] = {0}, num[N] = {0};
  char chr[N];
  scanf("%d %s",&n,chr);
  b[0] = strlen(chr);
  for(int i = 1; i <= b[0]; i++)
    b[i] = chr[b[0]-i] - '0';
  
  num[0] = num[1] = 1;
  for(int i = 2; i <= n; i++){
    Multiply(num, i);
  }

  for(int i = num[0]; i >= 1; i--){
    if(find_num(num, b, i))count++;
  }

  printf("%d",count);
  return 0;
}

// int main(){
//   int num_1[N]={0},num_2[N]={0};
//   num_1[0] = num_2[0] =2;
//   num_1[2] = num_2[2] =1;
  
//   printf("%d",find_num(num_1,num_2,1));
//   return 0;
// }