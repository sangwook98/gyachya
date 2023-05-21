#include <iostream>
#include <stack>

using namespace std;
int k, n, ans;
stack<int> s;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> k;
    while (k--)
    {
        cin >> n;
        if (n == 0)
            s.pop();
        else
            s.push(n);
    }
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    cout << ans;

    return 0;
}