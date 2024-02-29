#include <iostream>
#include <Windows.h>
using namespace std;

// Функція для введення матриці
void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// Функція для виводу матриці
void Print(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для обчислення добутку елементів у рядках без від'ємних елементів
int productOfPositiveRows(int** a, const int rowCount, const int colCount) {
    int product = 1;
    for (int i = 0; i < rowCount; i++) {
        int rowProduct = 1;
        bool isPositive = true;
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] < 0) {
                isPositive = false;
                break;
            }
            rowProduct *= a[i][j];
        }
        if (isPositive) {
            product *= rowProduct;
        }
    }
    return product;
}

// Функція для обчислення максимуму серед сум елементів діагоналей
void maxDiagonalSum(int** a, const int rowCount, const int colCount) {
    int maxSum = INT_MIN;
    for (int l = 0; l < rowCount + colCount - 1; l++) {
        int sum = 0;
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                if (i + j == l) {
                    sum += a[i][j];
                }
            }
        }
        maxSum = max(maxSum, sum);
    }
    cout << "Максимум серед сум елементів діагоналей: " << maxSum << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    int rowCount, colCount;
    cout << "Введіть розмірність матриці (rowCount x colCount): ";
    cin >> rowCount >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }
    Input(a, rowCount, colCount);
    cout << "Введена матриця: " << endl;
    Print(a, rowCount, colCount);
    cout << "Добуток елементів у рядках без від'ємних елементів: " << productOfPositiveRows(a, rowCount, colCount) << endl;
    maxDiagonalSum(a, rowCount, colCount);
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
