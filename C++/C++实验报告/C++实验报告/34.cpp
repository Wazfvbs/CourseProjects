#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    double score;

public:
    Student(const std::string& name, double score) : name(name), score(score) {}

    friend void findHighLow(const std::vector<Student>& students, Student& highest, Student& lowest);

    void print() const {
        std::cout << "Name: " << name << ", Score: " << score << std::endl;
    }
};

void findHighLow(const std::vector<Student>& students, Student& highest, Student& lowest) {
    if (students.empty()) return;

    highest = students[0];
    lowest = students[0];

    for (size_t i = 1; i < students.size(); ++i) {
        if (students[i].score > highest.score) {
            highest = students[i];
        }
        if (students[i].score < lowest.score) {
            lowest = students[i];
        }
    }
}

int main() {
    std::vector<Student> students = {
        {"Alice", 85.5},
        {"Bob", 92.3},
        {"Charlie", 78.4},
        {"David", 88.1}
    };

    Student highest("", 0.0);
    Student lowest("", 100.0);

    findHighLow(students, highest, lowest);

    std::cout << "Highest score:\n";
    highest.print();
    std::cout << "Lowest score:\n";
    lowest.print();

    return 0;
}

