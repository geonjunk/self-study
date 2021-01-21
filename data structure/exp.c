#include<stdio.h>

int exp(int x, int n) {//지수를 줄이는데 중점
	if (n == 0)return 1;
	if (n % 2 > 0) return exp(x*x, n / 2)*x;
	else return exp(x*x, n / 2);
}

int main(void) {
	printf("2의 10제곱 : %d\n", exp(3,5));
	return 0;
}