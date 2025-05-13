#include <iostream>

void sort(int &a, int &b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

int main() {
    int x, y;
    std::cout << "Enter two integers: ";
    std::cin >> x >> y;
    sort(x, y);
    std::cout << "Sorted: " << x << " " << y << std::endl;
    return 0;
}

