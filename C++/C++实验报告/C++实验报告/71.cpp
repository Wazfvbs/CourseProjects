#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// 父类 DataRec
class DataRec {
public:
    virtual void input() = 0;
    virtual void save(ofstream &out) = 0;
    virtual ~DataRec() {}
};

// 学生类 Student
class Student : virtual public DataRec {
protected:
    string studentID;
    string name;
    int age;

public:
    void input() override {
        cout << "Enter student ID: ";
        cin >> studentID;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student age: ";
        cin >> age;
    }

    void save(ofstream &out) override {
        out << "Student" << endl;
        out << "ID: " << studentID << endl;
        out << "Name: " << name << endl;
        out << "Age: " << age << endl;
    }
};

// 教师类 Professor
class Professor : virtual public DataRec {
protected:
    string employeeID;
    string name;
    string department;

public:
    void input() override {
        cout << "Enter professor employee ID: ";
        cin >> employeeID;
        cout << "Enter professor name: ";
        cin >> name;
        cout << "Enter department: ";
        cin >> department;
    }

    void save(ofstream &out) override {
        out << "Professor" << endl;
        out << "Employee ID: " << employeeID << endl;
        out << "Name: " << name << endl;
        out << "Department: " << department << endl;
    }
};

// 职员类 Staff
class Staff : virtual public DataRec {
protected:
    string employeeID;
    string name;
    string position;

public:
    void input() override {
        cout << "Enter staff employee ID: ";
        cin >> employeeID;
        cout << "Enter staff name: ";
        cin >> name;
        cout << "Enter position: ";
        cin >> position;
    }

    void save(ofstream &out) override {
        out << "Staff" << endl;
        out << "Employee ID: " << employeeID << endl;
        out << "Name: " << name << endl;
        out << "Position: " << position << endl;
    }
};

// 学生助教类 StudentStaff
class StudentStaff : public Student, public Staff {
public:
    void input() override {
        cout << "Enter student-staff details: " << endl;
        Student::input();
        Staff::input();
    }

    void save(ofstream &out) override {
        out << "StudentStaff" << endl;
        Student::save(out);
        Staff::save(out);
    }
};

int main() {
    vector<DataRec*> records;
    char choice;
    do {
        cout << "Choose the type of record to enter (s: Student, p: Professor, t: Staff, a: StudentStaff, q: Quit): ";
        cin >> choice;

        DataRec* record = nullptr;
        if (choice == 's') {
            record = new Student();
        } else if (choice == 'p') {
            record = new Professor();
        } else if (choice == 't') {
            record = new Staff();
        } else if (choice == 'a') {
            record = new StudentStaff();
        } else if (choice == 'q') {
            break;
        } else {
            cout << "Invalid choice!" << endl;
            continue;
        }

        record->input();
        records.push_back(record);

    } while (choice != 'q');

    ofstream outFile("university_records.txt");
    for (auto rec : records) {
        rec->save(outFile);
        outFile << "--------------------------" << endl;
    }
    outFile.close();

    // 清理动态分配的内存
    for (auto rec : records) {
        delete rec;
    }

    cout << "Data saved to university_records.txt" << endl;
    return 0;
}

