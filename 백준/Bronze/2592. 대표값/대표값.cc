#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
    int arr[1000] = {0};
    int total = 0;
    int maxi = 0;
    int index, r;

    for (int i = 0; i < 10; i++)
    {
        cin >> r;
        arr[r] += 1;
        total += r;
    }

    for (int i = 0; i < 1000; i++)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i];
            index = i;
        }
    }

    cout << total / 10 << "\n"
         << index;
    return 0;
}