//
//  workplace1.cpp
//  Workplace
//
//  Created by Иван Клочков on 29.01.2024.
//

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printPermutations(T arr[], int size) {
    for (;;) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        if (!next_permutation(arr, arr + size)) {
            break;
        }
    }
}

template <typename T>
void inputArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int main() {
    int size;
    cin >> size;

    string firstElement;
    cin >> firstElement;

    if (firstElement.find('.') != string::npos) {
        double* array = new double[size];
        array[0] = stod(firstElement);
        inputArray(array + 1, size - 1);
        printPermutations(array, size);
        delete[] array;
    } else {
        int* array = new int[size];
        array[0] = stoi(firstElement);
        inputArray(array + 1, size - 1);
        printPermutations(array, size);
        delete[] array;
    }

    return 0;
}

