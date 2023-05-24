#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;
int n, k, t;
int arr[10001];
long long answer;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (n <= k)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        arr[i] = t;
    }

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1] - arr[i];
        answer += arr[i];
    }

    sort(arr, arr + n - 1);

    for (int i = 0; i < k - 1; i++)
    {
        answer -= arr[n - 2 - i];
    }

    cout << answer;
}