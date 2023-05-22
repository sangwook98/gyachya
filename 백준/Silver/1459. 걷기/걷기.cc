#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;
long long int x, y, w, s, ans;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> x >> y >> w >> s;

    if (x < y)
        swap(x, y);

    ans = min((x + y) * w, y * s + (x - y) * w);
    ans = min(ans, (x + y) % 2 ? (x - 1) * s + w : x * s);

    cout << ans;

    return 0;
}
