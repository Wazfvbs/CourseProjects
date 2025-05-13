#include <iostream>
#include <cstring>

class Stock {
public:
    Stock(const char* na, int q = 1000, double p = 8.98) {
        strncpy(stockcode, na, sizeof(stockcode) - 1);
        stockcode[sizeof(stockcode) - 1] = '\0';
        quan = q;
        price = p;
    }

    void print() const {
        std::cout << "Stock code: " << stockcode
                  << ", Quantity: " << quan
                  << ", Price: " << price
                  << std::endl;
    }

private:
    char stockcode[30];
    int quan;
    double price;
};

int main() {
    Stock stock1("AAPL", 500, 150.75);
    Stock stock2("GOOGL");

    stock1.print();
    stock2.print();

    return 0;
}

