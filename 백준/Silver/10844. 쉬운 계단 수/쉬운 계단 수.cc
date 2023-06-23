#include <queue>
#include <stdio.h>
#include <string>
using namespace std;
int dp[10]{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    prev_dp[10]{0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, n;
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (j == 0) {
        dp[0] = prev_dp[1];
      } else if (j == 9) {
        dp[9] = prev_dp[8];
      } else
        dp[j] = prev_dp[j - 1] + prev_dp[j + 1];
    }
    for (int j = 0; j < 10; ++j) {
      dp[j] %= 1000000000;
      prev_dp[j] = dp[j];
    }
  }
  long long total = 0;
  for (int j = 0; j < 10; ++j) {
    total += prev_dp[j];
    total %= 1000000000;
  }
  printf("%d", total);
  return 0;
}