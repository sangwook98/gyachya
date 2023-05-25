#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int check(string s, string b)
{
    int cnt = 0, i = 1, n = s.size();
    for (; i < n - 1; i++)
    {
        if (s[i - 1] != b[i - 1])
        {
            s[i - 1] = s[i - 1] == '1' ? '0' : '1';
            s[i] = s[i] == '1' ? '0' : '1';
            s[i + 1] = s[i + 1] == '1' ? '0' : '1';
            cnt++;
        }
    }

    if (s[i - 1] != b[i - 1])
    {
        s[i - 1] = s[i - 1] == '1' ? '0' : '1';
        s[i] = s[i] == '1' ? '0' : '1';
        cnt++;
    }

    if (s[n - 1] != b[n - 1])
        cnt = 100001;

    return cnt;
}

int n, answer;
string s, b;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s >> b;

    answer = check(s, b);

    s[0] = s[0] == '1' ? '0' : '1';
    s[1] = s[1] == '1' ? '0' : '1';
    answer = min(answer, check(s, b) + 1);

    answer = answer == 100001 ? -1 : answer;
    cout << answer;
}