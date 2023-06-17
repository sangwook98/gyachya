#include <cstdio>
#include <queue>
#include <string>
using namespace std;
struct Node {
  int x, y, cnt;
  Node(int a, int b, int c) { x = a, y = b, cnt = c; }
};
int INF{1000001};

int n, m, k;
int graph[1001][1001];
int dis[1001][1001][11];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%1d", &graph[i][j]);
      fill_n(dis[i][j], k + 1, INF);
    }
  }
  fill_n(dis[0][0], k + 1, 1);

  queue<Node> q;
  q.push({0, 0, k});

  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
    q.pop();
    if (x == n - 1 && y == m - 1)
      break;

    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k], ny = y + dy[k];
      if (check(nx, ny)) {
        if (graph[nx][ny] == 0 && dis[nx][ny][cnt] > dis[x][y][cnt] + 1) {
          dis[nx][ny][cnt] = dis[x][y][cnt] + 1;
          q.push({nx, ny, cnt});
        } else if (graph[nx][ny] == 1 && cnt > 0 &&
                   dis[nx][ny][cnt - 1] > dis[x][y][cnt] + 1) {
          dis[nx][ny][cnt - 1] = dis[x][y][cnt] + 1;
          q.push({nx, ny, cnt - 1});
        }
      }
    }
  }

  int answer = INF;
  for (int i = 0; i <= k; ++i) {
    if (answer > dis[n - 1][m - 1][i])
      answer = dis[n - 1][m - 1][i];
  }
  answer = answer == INF ? -1 : answer;
  printf("%d", answer);

  return 0;
}