#include <iostream>
using namespace std;

class PrimeChecker {
public:
    virtual bool isPrime(int n, int i = 2) const {
        if (n <= 2) return (n == 2);
        if (n % i == 0) return false;
        if (i * i > n) return true;
        return isPrime(n, i + 1);
    }
};

class DerivedPrimeChecker : public PrimeChecker {
public:
    bool checkPrime(int n) const {
        return isPrime(n);
    }
};

int main() {
    DerivedPrimeChecker checker;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (checker.checkPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}

