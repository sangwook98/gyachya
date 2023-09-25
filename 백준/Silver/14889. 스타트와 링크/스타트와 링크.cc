#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
// 14:49start
int n, answer{100000000};
int graph[21][21];
bool is_red[21];

void dfs(int index, int count) {
  if (count == n / 2) {
    int total = 0, res = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (is_red[i] && is_red[j]) {
          total += graph[i][j];
        } else if (!is_red[i] && !is_red[j]) {
          res += graph[i][j];
        }
      }
    }
    answer = min(answer, abs(total - res));
    return;
  }
  for (int i = index; i < n; i++) {
    if (!is_red[i]) {
      is_red[i] = true;
      dfs(i + 1, count + 1);
      is_red[i] = false;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);
  }
  dfs(0, 0);
  printf("%d", answer);
  return 0;
}