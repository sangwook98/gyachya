#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;
int t, n;
stack<int> s;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int i = 0;
        scanf("%d", &n);
        while (pow(2, i) <= n)
            i++;
        i--;
        while (n)
        {
            if (n >= pow(2, i))
            {
                n -= pow(2, i);
                s.push(i);
            }
            i--;
        }
        while (!s.empty())
        {
            printf("%d ", s.top());
            s.pop();
        }
    }

    return 0;
}