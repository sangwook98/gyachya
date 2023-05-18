#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
    int maxi = 0;
    int total = 0;
    int a, b;

    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        total -= a;
        total += b;
        maxi = max(maxi, total);
    }
    cout << maxi;

    return 0;
}