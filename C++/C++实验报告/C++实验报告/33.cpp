#include <iostream>

class Number {
private:
    double value;

public:
    Number(double val) : value(val) {}

    friend double squareDifference(const Number& a, const Number& b);
};

double squareDifference(const Number& a, const Number& b) {
    return (a.value * a.value) - (b.value * b.value);
}

int main() {
    Number num1(5.0);
    Number num2(3.0);

    std::cout << "Square difference: " << squareDifference(num1, num2) << std::endl;

    return 0;
}

