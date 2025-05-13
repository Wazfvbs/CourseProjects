#include <iostream>
using namespace std;

// 函数模板，用于求数组中的最大元素
template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int intArr[] = {1, 5, 3, 9, 7};
    double doubleArr[] = {1.1, 5.5, 3.3, 9.9, 7.7};

    int intMax = findMax(intArr, 5);
    double doubleMax = findMax(doubleArr, 5);

    cout << "Max in int array: " << intMax << endl;
    cout << "Max in double array: " << doubleMax << endl;

    return 0;
}

