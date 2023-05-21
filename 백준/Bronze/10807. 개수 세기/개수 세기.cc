#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int n, t;
int d[201];
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        d[t + 100]++;
    }
    scanf("%d", &t);
    printf("%d", d[t + 100]);
    return 0;
}