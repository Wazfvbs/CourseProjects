#include <iostream>
#include <ctime>

class Date {
private:
    int year, month, day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    friend int daysBetween(const Date& date1, const Date& date2);

    void print() const {
        std::cout << year << "-" << month << "-" << day << std::endl;
    }
};

int daysBetween(const Date& date1, const Date& date2) {
    std::tm a = {0, 0, 0, date1.day, date1.month - 1, date1.year - 1900};
    std::tm b = {0, 0, 0, date2.day, date2.month - 1, date2.year - 1900};
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    double difference = std::difftime(y, x) / (60 * 60 * 24);
    return std::abs(static_cast<int>(difference));
}

int main() {
    Date date1(2023, 5, 30);
    Date date2(2024, 5, 30);

    std::cout << "Days between: " << daysBetween(date1, date2) << " days" << std::endl;

    return 0;
}

