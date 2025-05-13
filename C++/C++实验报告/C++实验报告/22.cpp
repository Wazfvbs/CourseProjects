#include <iostream>

class Date {
public:
    void printDate() const {
        std::cout << year << "-" << month << "-" << day << std::endl;
    }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
private:
    int day, month, year;
};

int main() {
    Date date;
    date.setYear(2024);
    date.setMonth(5);
    date.setDay(30);
    date.printDate();
    return 0;
}

