#include <iostream>

class counter {
public:
    counter(int number) : value(number) {}
    void increment() { ++value; }
    void decrement() { --value; }
    int getvalue() const { return value; }
    void print() const { std::cout << "Counter value: " << value << std::endl; }
private:
    int value;
};

int main() {
    counter c(10);
    c.increment();
    c.print();
    c.decrement();
    c.print();
    return 0;
}

