#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int n, t;
int mini = 1e6;
int maxi = -1e6;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        // mini = t < mini ? t : mini;
        mini = min(t, mini);
        maxi = max(t, maxi);
    }
    printf("%d %d", mini, maxi);
    return 0;
}