#include <iostream>
using namespace std;

// 函数模板，用于冒泡排序
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int intArr[] = {5, 1, 4, 2, 8};
    double doubleArr[] = {5.5, 1.1, 4.4, 2.2, 8.8};

    bubbleSort(intArr, 5);
    bubbleSort(doubleArr, 5);

    cout << "Sorted int array: ";
    for (int i = 0; i < 5; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    cout << "Sorted double array: ";
    for (int i = 0; i < 5; ++i) {
        cout << doubleArr[i] << " ";
    }
    cout << endl;

    return 0;
}

