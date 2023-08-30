/*2253733 信20 廖耀文*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	double a;
	long int b;
	long long int c;
	printf("请输一个[0...100亿）之间的数字;\n");
	scanf("%lf", &a);
	b =(int)(a / 1000000000);
	printf("十亿位       ; %ld\n", b);
	c = (long long)b * 1000000000;
	a = a - c;
	b = (int)(a / 100000000);
	printf("亿位         ; %ld\n", b);
	c = (long long)b * 100000000;
	a = a - c;
	b = (int)(a / 10000000);
	printf("千万位       ; %ld\n", b);
	c = (long long)b * 10000000;
	a = a - c;
	b = (int)(a / 1000000);
	printf("百万位       ; %ld\n", b);
	c = (long long)b * 1000000;
	a = a - c;
	b = (int)(a / 100000); 
	printf("十万位       ; %ld\n", b);
	c = (long long)b * 100000;
	a = a - c;
	b = (int)(a / 10000);
	printf("万位         ; %ld\n", b);
	c = (long long)b * 10000;
	a = a - c;
	b = (int)(a / 1000);
	printf("千位         ; %ld\n", b);
	c = (long long)b * 1000;
	a = a - c;
	b = (int)(a / 100);
	printf("百位         ; %ld\n", b);
	c = (long long)b * 100;
	a = a - c;
	b = (int)(a / 10);
	printf("十位         ; %ld\n", b);
	c = (long long)b * 10;
	a = a - c;
	b = (int)(a / 1);
	printf("圆           ; %ld\n", b);
	c = (long long)b * 1;
	a = a - c;
	a = a * 100 + 0.5;
	b = (int)(a / 10);
	printf("角           ; %ld\n", b);
	a = a - b * 10;
	b = (int)(a / 1);
	printf("分           ; %ld\n", b);
	return 0;
}