#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct Data {
  int x, y, cnt;
  Data(int a, int b, int c) { x = a, y = b, cnt = c; }
};

int n, m;
int INF{1000001};
int graph[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dis[1001][1001];
int brk_dis[1001][1001];
int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%1d", &graph[i][j]);
      dis[i][j] = INF, brk_dis[i][j] = INF;
    }
  }

  queue<Data> q;
  q.push({0, 0, 0});
  dis[0][0] = 1;
  brk_dis[0][0] = 1;

  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
    q.pop();
    if (x == n - 1 && y == m - 1)
      break;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (check(nx, ny)) {

        if (graph[nx][ny] == 0) {
          if (cnt == 0 && dis[nx][ny] > dis[x][y] + 1) {
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny, cnt});
          } else if (cnt == 1 && brk_dis[nx][ny] > brk_dis[x][y] + 1) {
            brk_dis[nx][ny] = brk_dis[x][y] + 1;
            q.push({nx, ny, cnt});
          }

        } else {
          if (cnt == 0) {
            brk_dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny, cnt + 1});
          }
        }
      }
    }
  }
  int answer = min(dis[n - 1][m - 1], brk_dis[n - 1][m - 1]);
  answer = answer == INF ? -1 : answer;
  printf("%d", answer);
}