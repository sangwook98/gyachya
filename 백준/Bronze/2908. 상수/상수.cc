#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int c, d, e;
    c = stoi(a);
    d = stoi(b);
    e = (c > d) ? c : d;
    cout << e;

    return 0;
}