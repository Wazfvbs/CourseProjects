#include <iostream>
using namespace std;

// 基类Car
class Car {
protected:
    double distance;  // 距离，单位：英里
public:
    Car(double d) : distance(d) {}
    
    // 虚函数，计算并显示通过这段距离的时间
    virtual void travel_time() {
        double speed = 80.0;  // 每小时80英里
        double time = distance / speed;
        cout << "Travel time in miles: " << time << " hours" << endl;
    }
};

// 派生类Kilometre
class Kilometre : public Car {
public:
    Kilometre(double d) : Car(d) {}
    
    // 覆盖基类的travel_time函数
    void travel_time() override {
        double speed = 120.0;  // 每小时120千米
        double time = distance / speed;
        cout << "Travel time in kilometers: " << time << " hours" << endl;
    }
};

int main() {
    Car car1(160);  // 160英里
    Kilometre car2(160);  // 160千米
    
    car1.travel_time();
    car2.travel_time();
    
    return 0;
}

