#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int t, n, p;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int mini = 100;
        int maxi = 0;

        while (n--)
        {
            scanf("%d", &p);
            mini = min(p, mini);
            maxi = max(p, maxi);
        }
        printf("%d\n", (maxi - mini) * 2);
    }

    return 0;
}