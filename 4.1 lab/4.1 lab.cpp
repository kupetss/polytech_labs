#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "N = ";
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = a[0], maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (a[j] == a[i])
                count++;

        if (count > maxCount)
        {
            maxCount = count;
            result = a[i];
        }
    }

    cout << "Number: " << result << ", count: " << maxCount << endl;
    return 0;
}
