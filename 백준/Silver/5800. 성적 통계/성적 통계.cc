#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int k, n, a;
int num = 1;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> k;
    while (k--)
    {
        vector<int> v;
        int gap = 0;
        cin >> n;
        while (n--)
        {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), greater<int>());

        for (int i = 1; i < v.size(); i++)
        {
            gap = max(gap, v[i - 1] - v[i]);
        }

        cout << "Class " << num
             << "\n";
        cout << "Max " << *v.begin() << ", "
             << "Min " << *--v.end() << ", "
             << "Largest gap " << gap << "\n";

        num++;
    }

    return 0;
}