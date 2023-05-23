#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int t, n, k, maxi;
vector<int> v;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t--)
    {
        long long answer = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        maxi = v.back();
        v.pop_back();

        while (!v.empty())
        {
            if (v.back() < maxi)
                answer += maxi - v.back();

            else
                maxi = v.back();

            v.pop_back();
        }
        cout << answer << "\n";
    }
}