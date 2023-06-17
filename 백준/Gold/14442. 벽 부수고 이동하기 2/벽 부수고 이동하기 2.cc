#include <cstdio>
#include <queue>
#include <string>
using namespace std;
struct Node {
  int x, y, dis, wall;
  Node(int a, int b, int c, int d) { x = a, y = b, dis = c, wall = d; }
};
int INF{1000001};

int n, m, k, answer{INF};
int graph[1001][1001];
bool visited[1001][1001][11];

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
    }
  }

  queue<Node> q;
  q.push({0, 0, 1, k});
  visited[0][0][k] = true;

  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, dis = q.front().dis,
        wall = q.front().wall;
    q.pop();
    if (x == n - 1 && y == m - 1) {
      answer = dis;
      break;
    }

    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k], ny = y + dy[k];
      if (check(nx, ny) && !visited[nx][ny][wall]) {
        if (graph[nx][ny] == 0) {
          visited[nx][ny][wall] = true;
          q.push({nx, ny, dis + 1, wall});
        } else if (graph[nx][ny] == 1 && wall > 0 &&
                   !visited[nx][ny][wall - 1]) {
          visited[nx][ny][wall - 1] = true;
          q.push({nx, ny, dis + 1, wall - 1});
        }
      }
    }
  }

  answer = answer == INF ? -1 : answer;
  printf("%d", answer);

  return 0;
}