#include <iostream>
#include <vector>
#include <string>

class Guest {
public:
    Guest(int id, const std::string& name) : id(id), name(name) {}

    void print() const {
        std::cout << "Guest ID: " << id << ", Name: " << name << std::endl;
    }

    static int getTotalGuests() {
        return totalGuests;
    }
	static int totalGuests;
private:
    int id;
    std::string name;
    
};

int Guest::totalGuests = 0;

int main() {
    std::vector<Guest> guests;
    std::string name;
    while (true) {
        std::cout << "Enter guest name (or 'done' to finish): ";
        std::cin >> name;
        if (name == "done") break;
        guests.push_back(Guest(++Guest::totalGuests, name));
    }

    std::cout << "Total guests: " << Guest::getTotalGuests() << std::endl;
    for (size_t i = 0; i < guests.size(); ++i) {
        guests[i].print();
    }

    return 0;
}

