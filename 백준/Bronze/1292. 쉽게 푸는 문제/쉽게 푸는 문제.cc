#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int a, b, total, cnt;
int j = 1;
int main()
{
    scanf("%d %d", &a, &b);

    for (int i = 1; i < b + 1; i++)
    {
        cnt++;
        if (a <= i)
            total += j;

        if (j == cnt)
            j++, cnt = 0;
    }

    printf("%d", total);

    return 0;
}