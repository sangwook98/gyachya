#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int n, s, r, t, ans;
int boat[11];
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    fill_n(boat, 11, 1);

    cin >> n >> s >> r;
    while (s--)
        cin >> t, boat[t]--;
    while (r--)
        cin >> t, boat[t]++;

    for (int i = 1; i < n; i++)
    {
        if ((boat[i] == 2 && boat[i + 1] == 0) || (boat[i] == 0 && boat[i + 1] == 2))
            boat[i] = 1, boat[i + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (boat[i] == 0)
            ans++;
    }
    cout << ans;
    return 0;
}