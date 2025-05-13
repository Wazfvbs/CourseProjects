#include <iostream>
#include <cmath>

double f(double x) {
    return x * x - 2;  // Example function: x^2 - 2
}

double bisection(double a, double b, double tol) {
    double mid;
    while ((b - a) / 2 > tol) {
        mid = (a + b) / 2;
        if (f(mid) == 0.0) return mid;
        else if (f(mid) * f(a) < 0) b = mid;
        else a = mid;
    }
    return mid;
}

int main() {
    double root = bisection(0, 2, 0.0001);
    std::cout << "Root: " << root << std::endl;
    return 0;
}

