#include <iostream>
#include <iomanip>
using namespace std;

class Table {
public:
    Table(char start, char end) : start(start), end(end) {}
    void ascii() const;
protected:
    char start, end;
};

void Table::ascii() const {
    for (char i = start; i <= end; ++i) {
        cout << setw(4) << (int)i << " " << i;
        if ((i - start + 1) % 12 == 0) cout << "\n";
    }
    cout << "\n";
}

class DerTable : public Table {
public:
    DerTable(char start, char end, const char* title) : Table(start, end), title(title) {}
    void print() const;
protected:
    const char* title;
};

void DerTable::print() const {
    cout << title << "\n";
    Table::ascii();
}

int main() {
    DerTable ob('a', 'z', "ASCII value-char");
    ob.print();
    return 0;
}

