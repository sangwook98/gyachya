#include <queue>
#include <stdio.h>
#include <string>
using namespace std;

int dp[501], prev_dp[501], answer, n, t;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      scanf("%d", &t);
      prev_dp[j] = dp[j];
      if (j == 1)
        dp[j] = prev_dp[j] + t;
      else if (j == i)
        dp[j] = prev_dp[j - 1] + t;
      else
        dp[j] = max(prev_dp[j - 1], prev_dp[j]) + t;
    }
  }
  for (int i = 1; i <= n; ++i)
    answer = max(answer, dp[i]);

  printf("%d", answer);

  return 0;
}