#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int a, b, c, d, maxi, ind;
int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> a >> b >> c >> d;
        if (maxi < a + b + c + d)
        {
            maxi = a + b + c + d;
            ind = i;
        }
    }
    cout << ind + 1 << ' ' << maxi;

    return 0;
}