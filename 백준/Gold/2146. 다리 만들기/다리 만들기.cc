#include <cstdio>
#include <queue>
#include <string>
using namespace std;
struct Node {
  int x, y, num;
  Node(int a, int b, int c) { x = a, y = b, num = c; }
};

int graph[101][101];
int dis[101][101];
int INF{100001};
int n, answer{INF};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    fill_n(dis[i], n, INF);
    for (int j = 0; j < n; ++j)
      scanf("%d", &graph[i][j]);
  }

  // 각 섬 구역 나누기
  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (graph[i][j] == 1) {
        cnt++;
        queue<Node> q;
        q.push({i, j, 0});
        graph[i][j] = cnt;
        while (!q.empty()) {
          int x = q.front().x, y = q.front().y;
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (check(nx, ny) && graph[nx][ny] == 1) {
              graph[nx][ny] = cnt;
              q.push({nx, ny, 0});
            }
          }
        }
      }
    }
  }
  // 각 섬 거리 업데이트
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (graph[i][j] != 0 && dis[i][j] == INF) {

        dis[i][j] = 0;
        queue<Node> q;
        q.push({i, j, graph[i][j]});

        while (!q.empty()) {
          int x = q.front().x, y = q.front().y, num = q.front().num;
          q.pop();

          for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];

            if (check(nx, ny) && dis[nx][ny] > dis[x][y] + 1) {
              if (graph[nx][ny] == num) {
                q.push({nx, ny, num});
                dis[nx][ny] = 0;
              } else if (graph[nx][ny] == 0) {
                q.push({nx, ny, num});
                dis[nx][ny] = dis[x][y] + 1;
              } else {
                answer = min(answer, dis[x][y]);
              }
            }
          }
        }
      }
    }
  }
  printf("%d", answer);
  return 0;
}