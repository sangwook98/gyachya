#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int arr[8] = {0};
    int tmp[8] = {0};
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &arr[i]);
        tmp[i] = arr[i];
    }

    sort(tmp, tmp + 8);
    int ans = 0;
    vector<int> v;
    for (int i = 0; i < 8; i++)
    {
        if (tmp[0] == arr[i] || tmp[1] == arr[i] || tmp[2] == arr[i])
            continue;
        else
        {
            ans += arr[i];
            v.push_back(i);
        }
    }
    printf("%d\n", ans);
    for (auto i : v)
        printf("%d ", i + 1);

    return 0;
}