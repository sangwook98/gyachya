#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
#define INF 1000000000
using namespace std;

// 10:15 start
int n;
int maxi = -INF;
int mini = INF;

int nums[11], buho[4];

void dfs(int total, int index) {
  if (index == n) {
    maxi = max(maxi, total);
    mini = min(mini, total);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (buho[i]) {
      buho[i]--;
      if (i == 0)
        dfs(total + nums[index], index + 1);
      else if (i == 1)
        dfs(total - nums[index], index + 1);
      else if (i == 2)
        dfs(total * nums[index], index + 1);
      else if (i == 3)
        dfs(total / nums[index], index + 1);
      buho[i]++;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &nums[i]);

  for (int i = 0; i < 4; i++)
    scanf("%d", &buho[i]);

  dfs(nums[0], 1);

  printf("%d\n%d", maxi, mini);
  return 0;
}