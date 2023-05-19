#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int n, r;
string s;
vector<string> ss;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> s;
        s.erase(r - 1, 1);
        cout << s << '\n';
    }

    return 0;
}