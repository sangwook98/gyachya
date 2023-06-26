#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string>
using namespace std;

int n, dp[10001], arr[10001];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
  dp[1] = arr[1];
  dp[2] = arr[1] + arr[2];
  int answer = dp[2];
  for (int i = 3; i <= n; ++i) {
    dp[i] =
        max({dp[i - 1], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]});
    answer = max(answer, dp[i]);
  }
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", dp[i]);
  // }
  printf("%d", answer);
  return 0;
}