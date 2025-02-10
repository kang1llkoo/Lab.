#include <stdio.h>

int cnt1 = 0;
int cnt2 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt1++;
		return 1;
	}
	else return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
	int f[50];
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		cnt2++;
	}
	return f[n];
}

int main() {
	int n;
	scanf("%d", n);
	fib(n);
	fibonacci(n);
	printf("%d %d", cnt1, cnt2);
	return 0;
}