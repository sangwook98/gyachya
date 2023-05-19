#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;
int t, n;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; n > 0; i++, n /= 2)
        {
            if (n % 2 == 1)
                printf("%d ", i);
        }
    }

    return 0;
}