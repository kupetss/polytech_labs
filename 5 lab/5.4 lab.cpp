#include <iostream>
#include "tasks.h"

// Задание: динамический массив NxN. Элементы побочной диагонали умножить на элементы первой
// строки и записать в последний столбец.


using namespace std;

static int read_n()
{
    int n;
    cout << "Введите n: ";
    cin >> n;
    return n;
}

static int** create_matrix(int n)
{
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    return a;
}

static void fill_matrix(int** a, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
}

static int* copy_first_row(int** a, int n)
{
    int* f_row = new int[n];
    for (int i = 0; i < n; i++)
        f_row[i] = a[0][i];
    return f_row;
}

static void multiply_diagonal(int** a, int* f_row, int n)
{
    for (int i = 0; i < n; i++)
        a[i][n - 1] = a[i][n - 1 - i] * f_row[i];
}

static void print_matrix(int** a, int n)
{
    cout << "Результат:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

static void delete_matrix(int** a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

void lab4() {
    setlocale(LC_ALL, "RUS");

    int n = read_n();

    int** a = create_matrix(n);
    fill_matrix(a, n);

    int* f_row = copy_first_row(a, n);
    multiply_diagonal(a, f_row, n);

    print_matrix(a, n);

    delete[] f_row;
    delete_matrix(a, n);
}