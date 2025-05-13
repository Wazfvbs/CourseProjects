#include <iostream>
using namespace std;

// ����Car
class Car {
protected:
    double distance;  // ���룬��λ��Ӣ��
public:
    Car(double d) : distance(d) {}
    
    // �麯�������㲢��ʾͨ����ξ����ʱ��
    virtual void travel_time() {
        double speed = 80.0;  // ÿСʱ80Ӣ��
        double time = distance / speed;
        cout << "Travel time in miles: " << time << " hours" << endl;
    }
};

// ������Kilometre
class Kilometre : public Car {
public:
    Kilometre(double d) : Car(d) {}
    
    // ���ǻ����travel_time����
    void travel_time() override {
        double speed = 120.0;  // ÿСʱ120ǧ��
        double time = distance / speed;
        cout << "Travel time in kilometers: " << time << " hours" << endl;
    }
};

int main() {
    Car car1(160);  // 160Ӣ��
    Kilometre car2(160);  // 160ǧ��
    
    car1.travel_time();
    car2.travel_time();
    
    return 0;
}

