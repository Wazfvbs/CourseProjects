#include <iostream>
#include <cmath>

int sroot(int x) {
    return static_cast<int>(std::sqrt(x));
}

long sroot(long x) {
    return static_cast<long>(std::sqrt(x));
}

double sroot(double x) {
    return std::sqrt(x);
}

int main() {
    int x1;
    long x2;
    double x3;
	std::cin >>  x1 >>  x2 >>  x3 ;
    std::cout << "Int sqrt: " << sroot(x1) << std::endl;
    std::cout << "Long sqrt: " << sroot(x2) << std::endl;
    std::cout << "Double sqrt: " << sroot(x3) << std::endl;

    return 0;
}

