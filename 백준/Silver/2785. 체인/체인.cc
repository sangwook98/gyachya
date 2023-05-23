#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>

using namespace std;
int n, k;
long long answer;
int arr[500001];
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int start = 0, end = n - 1;

    while (start != end)
    {
        if (arr[start] == 0)
        {
            start++;
            continue;
        }
        else
        {
            arr[end - 1] += arr[end];
            end--;
            arr[start]--;
            answer++;
        }
    }
    cout << answer;
}