#include<stdio.h> 
#include<stdlib.h>

int euler(int n) {
    int ans = n;
    int i;
    for (i = 2; i*i <= ans; i++) {
        if (n % i == 0) {   
            ans = ans / i * (i-1);
            // 将相同的因子除去
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ans = ans / n * (n-1);
    }
    return ans;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",euler(n));
	}
	return 0;
}
