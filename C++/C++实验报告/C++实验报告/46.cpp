#include <iostream>
using namespace std;

class GCDCalculator {
public:
    virtual int gcd(int a, int b) const {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};

class DerivedGCDCalculator : public GCDCalculator {
public:
    int calculateGCD(int a, int b) const {
        return gcd(a, b);
    }
};

int main() {
    DerivedGCDCalculator calculator;
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int result = calculator.calculateGCD(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is " << result << "." << endl;

    return 0;
}

