#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;
int check(string s)
{
    if (s.size() == 1)
        return true;
    if (s.size() % 2 == 0)
        return false;

    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] == s[s.size() - i - 1])
            return false;
    }

    return check(s.substr(0, s.size() / 2));
}

int t;
string s;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;

    while (t--)
    {
        cin >> s;

        if (check(s))
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
}