#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include<math.h>

int main() {
	int n;
	long long int m;
	scanf("%d", &n);
	if (n == 1) {
		m = 1;
	}
	else {
		m= (long int)pow(4, n - 1) + (long int)pow(2, n - 1);
	}
	printf("%lld", m);
	return 0;
}