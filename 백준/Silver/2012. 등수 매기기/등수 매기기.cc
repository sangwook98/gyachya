#include <iostream>
#include <algorithm>

using namespace std;
int n, tmp;
long long ans;
int arr[500001];
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    tmp = n;
    while (tmp--)
        cin >> arr[tmp];
    sort(arr, arr + n);
    for (int i = 1; i <= n; i++)
        ans += abs(i - arr[i - 1]);

    cout << ans;
}