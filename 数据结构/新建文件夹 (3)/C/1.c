#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include<math.h>
#include <stdio.h>
#include <math.h>

int Nd10F(int n) {
    double phi = (1.0 + sqrt(5)) / 2.0;
    return (int)floor(n * log10(phi) - 0.5 * log10(5.0)) + 1;
}
int C(int n) {
    double phi1 = (1.0 + sqrt(5)) / 2.0;
    double phi2 = (1.0 - sqrt(5)) / 2.0;
    return (int)(-log10(sqrt(5)) + log10(pow(phi1, n + 1) - pow(phi2, n + 1)));
}
int D(int n) {
    return (int)log10(pow(((1 + sqrt(5)) / 2.0), n) / sqrt(5) - pow(((1 - sqrt(5)) / 2.0), n) / sqrt(5));
}
/*int main() {
    int n;
    scanf("%d", &n);
    double m;
    m= log10(pow(((1 + sqrt(5)) / 2.0), n) / sqrt(5) - pow(((1 - sqrt(5)) / 2.0), n) / sqrt(5));
    
    printf("%d\n", (int)m+1);

    return 0;
}*/
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", Nd10F(n));
}