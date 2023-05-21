#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int n, ans, v, i, tmp;
vector<int> vec;
int main()
{
    scanf("%d", &n);
    for (; i < n; i++)
    {
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    scanf("%d", &v);

    for (int i = 0; i < vec.size(); i++)
    {
        if (v == vec[i])
            ans++;
    }
    printf("%d", ans);
    return 0;
}