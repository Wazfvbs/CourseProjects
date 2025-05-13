#include <iostream>

class book {
public:
    book(int q, double p) : qu(q), price(p) {}

    void print() {
        std::cout << "qu * price: " << qu * price << std::endl;
    }

private:
    int qu;
    double price;
};

int main() {
    book books[5] = {
        book(1, 10.0),
        book(2, 20.0),
        book(3, 30.0),
        book(4, 40.0),
        book(5, 50.0)
    };

    for (int i = 0; i < 5; ++i) {
        books[i].print();
    }

    return 0;
}

