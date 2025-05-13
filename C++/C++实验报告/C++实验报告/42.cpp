#include <iostream>
#include <string>
using namespace std;

class Time {
public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    virtual void display() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
protected:
    int hours, minutes, seconds;
};

class Date {
public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}
    virtual void display() const {
        cout << month << "/" << day << "/" << year << endl;
    }
protected:
    int month, day, year;
};

class Birthtime : public Time, public Date {
public:
    Birthtime(int h, int m, int s, int mon, int d, int y, const string& name)
        : Time(h, m, s), Date(mon, d, y), childName(name) {}
    void display() const override {
        cout << "Child's Name: " << childName << endl;
        cout << "Birth Date: ";
        Date::display();
        cout << "Birth Time: ";
        Time::display();
    }
private:
    string childName;
};

int main() {
    Birthtime birth(12, 30, 45, 5, 10, 2003, "John Doe");
    birth.display();
    return 0;
}

