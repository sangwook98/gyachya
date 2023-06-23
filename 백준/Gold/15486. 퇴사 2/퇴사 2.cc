#include <queue>
#include <stdio.h>
#include <string>
using namespace std;

int dp[1500002], n, t[1500001], p[1500001];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &t[i], &p[i]);
  }

  for (int i = 1; i <= n; ++i) {
    dp[i] = max(dp[i - 1], dp[i]);
    if (t[i] + i <= 1500001)
      dp[t[i] + i] = max(dp[t[i] + i], dp[i] + p[i]);
    // printf("%d ", dp[i]);
  }
  printf("%d", max(dp[n], dp[n + 1]));
  return 0;
}