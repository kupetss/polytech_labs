#include <iostream>

// Задание: динамический массив NxN. Элементы побочной диагонали умножить на элементы первой 
// строки и записать в последний столбец.


using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите n: ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    int* f_row = new int[n];
    for (int i = 0; i < n; i++)
        f_row[i] = a[0][i];

    for (int i = 0; i < n; i++)
        a[i][n - 1] = a[i][n - 1 - i] * f_row[i];

    cout << "Результат:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    delete[] f_row;
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}