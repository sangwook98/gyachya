#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int n, total, answer;
int color[1000][3];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);

  for (int j = 1; j < n; ++j) {
    color[j][0] += min(color[j - 1][1], color[j - 1][2]);
    color[j][1] += min(color[j - 1][0], color[j - 1][2]);
    color[j][2] += min(color[j - 1][0], color[j - 1][1]);
  }
  answer = min(min(color[n - 1][0], color[n - 1][1]), color[n - 1][2]);

  printf("%d", answer);
  return 0;
}