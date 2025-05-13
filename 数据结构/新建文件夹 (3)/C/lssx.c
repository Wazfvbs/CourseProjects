/*#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include<math.h>
int count(int n) {
	int x = 0;
	int m = F(n);
	while (m > 0) {
		x++;
		m /= 10;
	}
	return x;
}
int F(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 1;
	}
	else {

		return F(n - 2) + F(n - 1);
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	printf("%d", count(n));
	return 0;
}*/