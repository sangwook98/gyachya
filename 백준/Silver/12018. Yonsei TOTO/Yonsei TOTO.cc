#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int n, m, tmp, ans, p, l;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int mil_arr[n];

    for (int j = 0; j < n; j++)
    {
        cin >> p >> l;
        int arr[p];
        for (int i = 0; i < p; i++)
            cin >> arr[i];

        if (p < l)
            mil_arr[j] = 1;
        else
        {
            sort(arr, arr + p, greater<int>());
            mil_arr[j] = arr[l - 1];
        }
    }

    sort(mil_arr, mil_arr + n);

    for (int i = 0; i < n; i++)
    {
        // cout << mil_arr[i] << " ";
        if (m >= mil_arr[i])
        {
            ans += 1;
            m -= mil_arr[i];
        }
    }
    cout << ans;
}