#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int arr[100], total, ind, r;
int main()
{

    for (int i = 0; i < 10; i++)
    {
        cin >> r;
        arr[r / 10]++;
        total += r;
    }

    for (int i = 0; i < 100; i++)
    {
        if (arr[ind] < arr[i])
            ind = i;
    }

    cout << total / 10 << "\n"
         << ind * 10;

    return 0;
}