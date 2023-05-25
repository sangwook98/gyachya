#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
string a, b;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    while (a.size() != b.size())
    {
        if (b.back() == 'A')
            b.pop_back();
        else
        {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }

    if (a == b)
        cout << 1;
    else
        cout << 0;
}