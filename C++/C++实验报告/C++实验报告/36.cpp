#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double x_val, double y_val) : x(x_val), y(y_val) {}

    friend double horizontalDistance(const Point& p1, const Point& p2);
    friend double verticalDistance(const Point& p1, const Point& p2);

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

double horizontalDistance(const Point& p1, const Point& p2) {
    return std::abs(p1.x - p2.x);
}

double verticalDistance(const Point& p1, const Point& p2) {
    return std::abs(p1.y - p2.y);
}

int main() {
    Point p1(3.0, 4.0);
    Point p2(7.0, 1.0);

    std::cout << "Horizontal distance: " << horizontalDistance(p1, p2) << std::endl;
    std::cout << "Vertical distance: " << verticalDistance(p1, p2) << std::endl;

    return 0;
}

