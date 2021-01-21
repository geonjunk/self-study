#include<stdio.h>

int fib(int n) {//재귀를 이용한 fibonaci
	if (n < 2) return n;
	return fib(n - 1) + fib(n - 2);
}

int fib2(int fib[],int n) {//DP를 이용한 fibonaci
	int i;
	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n];
}
int main(void) {
	int arr[10];
	printf("fib(5) : %d\n", fib(5));
	printf("Dp fib(5) : %d\n", fib2(arr,5));
	return 0;
}