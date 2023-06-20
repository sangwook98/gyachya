#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int stairs[300], dp[300];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &stairs[i]);

  dp[0] = stairs[0];
  dp[1] = stairs[0] + stairs[1];
  dp[2] = max(stairs[0], stairs[1]) + stairs[2];

  for (int i = 3; i < n; ++i) {
    dp[i] = dp[i - 3] + stairs[i - 1] + stairs[i];
    dp[i] = max(dp[i], dp[i - 2] + stairs[i]);
  }
  printf("%d", dp[n - 1]);
  return 0;
}