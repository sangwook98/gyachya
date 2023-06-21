#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int n, m, t, a, b;
int dp[100001];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t);
    dp[i] = dp[i - 1] + t;
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    printf("%d\n", dp[b] - dp[a - 1]);
  }

  return 0;
}