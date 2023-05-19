#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int arr[42], i, j, a, b;
int main()
{
    for (; i < 10; i++)
    {
        cin >> a;
        arr[a % 42]++;
    }
    for (; j < 42; j++)
    {
        if (arr[j] != 0)
            b++;
    }
    cout << b;
    return 0;
}