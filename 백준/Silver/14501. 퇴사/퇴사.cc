#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

// 09:32 start
int n, t, p;
int dp[16];
vector<pair<int, int>> v[16];

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &t, &p);
    if (i + t - 1 <= n)
      v[i + t - 1].push_back({i, p});
  }

  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    for (auto j : v[i]) {
      dp[i] = max(dp[i], dp[j.first - 1] + j.second);
    }
  }
  // for (int i = 1; i <= n; i++)
  //   printf("%d ", dp[i]);
  printf("%d", dp[n]);

  return 0;
}