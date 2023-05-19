#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int arr[42], x, ans;
int main()
{
    while (scanf("%d", &x) > 0)
    {
        if (arr[x % 42] == 0)
            ans++;
        arr[x % 42]++;
    }
    printf("%d", ans);
    return 0;
}