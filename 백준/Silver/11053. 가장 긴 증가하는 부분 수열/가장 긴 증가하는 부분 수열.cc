#include <queue>
#include <stdio.h>

using namespace std;

int num[1001], dp[1001], n, answer;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &num[i]);

  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (num[j] < num[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    answer = max(answer, dp[i]);
  printf("%d", answer);
  return 0;
}