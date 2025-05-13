#include <iostream>

int* fibonacci(int n) {
    int* fib = new int[n];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

int main() {
    int* fib = fibonacci(20);
    for (int i = 0; i < 20; ++i) {
        std::cout << fib[i] << " ";
    }
    delete[] fib;
    return 0;
}

