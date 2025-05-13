#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Input {
private:
    T value;
    T minValue;
    T maxValue;
    string promptMessage;

public:
    // 构造函数
    Input(string message, T minVal, T maxVal) : promptMessage(message), minValue(minVal), maxValue(maxVal) {
        getInput();
    }

    // 获取输入并进行范围检查
    void getInput() {
        while (true) {
            cout << promptMessage;
            cin >> value;
            if (value >= minValue && value <= maxValue) {
                break;
            } else {
                cout << "Value out of range. Please try again." << endl;
            }
        }
    }

    // 返回输入的值
    T getValue() {
        return value;
    }
};

int main() {
    Input<int> intInput("Enter an integer between 1 and 10: ", 1, 10);
    cout << "You entered: " << intInput.getValue() << endl;

    Input<double> doubleInput("Enter a double between 1.0 and 10.0: ", 1.0, 10.0);
    cout << "You entered: " << doubleInput.getValue() << endl;

    return 0;
}

