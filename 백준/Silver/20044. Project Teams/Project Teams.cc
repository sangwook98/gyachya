#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int n, ans{200000};
int arr[10000];
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int tmp = 2 * n;
    while (tmp--)
    {
        cin >> arr[tmp];
    }
    sort(arr, arr + 2 * n);

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, arr[i] + arr[2 * n - i - 1]);
    }
    cout << ans;
    return 0;
}