#include <iostream>
using namespace std;

class TwoDArray {
private:
    int rows, cols;
    int **data;
public:
    // 构造函数
    TwoDArray(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand() % 10;  // 随机初始化数组
            }
        }
    }
    
    // 从键盘输入数组的值
    void input() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter value for element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }
    
    // 友元函数重载运算符+
    friend TwoDArray operator+(const TwoDArray &a, const TwoDArray &b) {
        TwoDArray result(a.rows, a.cols);
        for (int i = 0; i < a.rows; ++i) {
            for (int j = 0; j < a.cols; ++j) {
                result.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return result;
    }
    
    // 友元函数重载运算符-
    friend TwoDArray operator-(const TwoDArray &a, const TwoDArray &b) {
        TwoDArray result(a.rows, a.cols);
        for (int i = 0; i < a.rows; ++i) {
            for (int j = 0; j < a.cols; ++j) {
                result.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return result;
    }
    
    // 打印数组
    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    // 析构函数
    ~TwoDArray() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int rows = 2, cols = 3;
    TwoDArray array1(rows, cols);  // 通过构造函数设置第一个二维数组
    TwoDArray array2(rows, cols);
    
    cout << "Input values for the second array:" << endl;
    array2.input();  // 从键盘输入第二个二维数组的值
    
    cout << "Array 1:" << endl;
    array1.print();
    cout << "Array 2:" << endl;
    array2.print();
    
    TwoDArray sum = array1 + array2;
    TwoDArray diff = array1 - array2;
    
    cout << "Sum of arrays:" << endl;
    sum.print();
    cout << "Difference of arrays:" << endl;
    diff.print();
    
    return 0;
}

