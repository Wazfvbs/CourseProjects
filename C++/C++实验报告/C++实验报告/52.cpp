#include <iostream>
using namespace std;

class TwoDArray {
private:
    int rows, cols;
    int **data;
public:
    // ���캯��
    TwoDArray(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = rand() % 10;  // �����ʼ������
            }
        }
    }
    
    // �Ӽ������������ֵ
    void input() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter value for element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }
    
    // ��Ԫ�������������+
    friend TwoDArray operator+(const TwoDArray &a, const TwoDArray &b) {
        TwoDArray result(a.rows, a.cols);
        for (int i = 0; i < a.rows; ++i) {
            for (int j = 0; j < a.cols; ++j) {
                result.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return result;
    }
    
    // ��Ԫ�������������-
    friend TwoDArray operator-(const TwoDArray &a, const TwoDArray &b) {
        TwoDArray result(a.rows, a.cols);
        for (int i = 0; i < a.rows; ++i) {
            for (int j = 0; j < a.cols; ++j) {
                result.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return result;
    }
    
    // ��ӡ����
    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    // ��������
    ~TwoDArray() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int rows = 2, cols = 3;
    TwoDArray array1(rows, cols);  // ͨ�����캯�����õ�һ����ά����
    TwoDArray array2(rows, cols);
    
    cout << "Input values for the second array:" << endl;
    array2.input();  // �Ӽ�������ڶ�����ά�����ֵ
    
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

