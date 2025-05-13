#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name) : name(name) {}
    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
    }
protected:
    std::string name;
};

class Score : public Person {
public:
    Score(const std::string& name, int score) : Person(name), score(score) {}
    void display() const override {
        Person::display();
        std::cout << "Score: " << score << std::endl;
    }
private:
    int score;
};

class Teacher : public Person {
public:
    Teacher(const std::string& name, const std::string& subject) 
        : Person(name), subject(subject) {}
    void display() const override {
        Person::display();
        std::cout << "Subject: " << subject << std::endl;
    }
private:
    std::string subject;
};

int main() {
    Score c1("Student1", 95);
    Teacher t1("Teacher1", "Math");

    std::cout << "Score object:\n";
    c1.display();

    std::cout << "\nTeacher object:\n";
    t1.display();

    return 0;
}

