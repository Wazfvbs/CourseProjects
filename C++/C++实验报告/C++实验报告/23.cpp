#include <iostream>
#include <cmath>

class cylinder {
public:
    cylinder(double r, double h) : radius(r), height(h) {
        volume = M_PI * radius * radius * height;
    }

    void vol() {
        std::cout << "Volume: " << volume << std::endl;
    }

private:
    double radius, height, volume;
};

int main() {
    cylinder cyl(3.0, 5.0);
    cyl.vol();
    return 0;
}

