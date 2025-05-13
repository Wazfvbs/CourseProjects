#include <iostream>
using namespace std;

class Building {
public:
    Building(int floors, int rooms, double area) : floors(floors), rooms(rooms), area(area) {}
    virtual void display() const {
        cout << "Floors: " << floors << ", Rooms: " << rooms << ", Area: " << area << endl;
    }
protected:
    int floors, rooms;
    double area;
};

class House : public Building {
public:
    House(int floors, int rooms, double area, int bedrooms, int bathrooms)
        : Building(floors, rooms, area), bedrooms(bedrooms), bathrooms(bathrooms) {}
    void display() const override {
        Building::display();
        cout << "Bedrooms: " << bedrooms << ", Bathrooms: " << bathrooms << endl;
    }
private:
    int bedrooms, bathrooms;
};

class Office : public Building {
public:
    Office(int floors, int rooms, double area, int extinguishers, int phones)
        : Building(floors, rooms, area), extinguishers(extinguishers), phones(phones) {}
    void display() const override {
        Building::display();
        cout << "Extinguishers: " << extinguishers << ", Phones: " << phones << endl;
    }
private:
    int extinguishers, phones;
};

int main() {
    House h(2, 5, 150.0, 3, 2);
    h.display();

    Office o(3, 10, 300.0, 5, 20);
    o.display();
    return 0;
}

