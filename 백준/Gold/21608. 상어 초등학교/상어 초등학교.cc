#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
// 10:54 start
int n;
int a, b, c, d, e;
int graph[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int like[401][4];

bool check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n * n; i++) {
    scanf("%d", &a);
    scanf("%d %d %d %d", &like[a][0], &like[a][1], &like[a][2], &like[a][3]);
    int x = 0, y = 0;
    int top_point = -1;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (graph[j][k] != 0)
          continue;
        int point = 0;
        for (int p = 0; p < 4; p++) {
          int nx = j + dx[p];
          int ny = k + dy[p];
          if (!check(nx, ny))
            continue;

          if (graph[nx][ny] == 0)
            point += 1;
          else if (graph[nx][ny] == like[a][0] || graph[nx][ny] == like[a][1] ||
                   graph[nx][ny] == like[a][2] || graph[nx][ny] == like[a][3])
            point += 10;
        }
        if (top_point < point) {
          top_point = point;
          x = j, y = k;
          // printf("%d %d %d\n", top_point, x, y);
        }
      }
    }
    graph[x][y] = a;
    // 비어있는 칸 중 좋아하는 학생 많은 칸
    // 인접한 칸 중 비어있는 칸 많은 칸
    // 행열 작은 우선순위
  }
  // 점수 구하기
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     printf("%d", graph[i][j]);
  //   }
  //   printf("\n");
  // }
  int answer[5] = {0, 0, 0, 0, 0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (!check(nx, ny))
          continue;

        for (int p = 0; p < 4; p++) {
          if (like[graph[i][j]][p] == graph[nx][ny])
            cnt++;
        }
      }
      answer[cnt]++;
    }
  }
  printf("%d", answer[1] + 10 * answer[2] + 100 * answer[3] + 1000 * answer[4]);

  return 0;
}