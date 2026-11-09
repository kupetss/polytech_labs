#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double fillAndPrint(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
        sum += arr[i];
    }
    cout << endl;
    return (double)sum / size;
}

int main()
{
    srand(time(0));

    int a[5], b[10];

    double avgA = fillAndPrint(a, 5);
    cout << "Average: " << avgA << endl;

    double avgB = fillAndPrint(b, 10);
    cout << "Average: " << avgB << endl;

    return 0;
}
