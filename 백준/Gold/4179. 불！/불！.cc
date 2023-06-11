#include <cstdio>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;

struct Data {
  int x, y, time, h_f;
  Data() {}
  Data(int a, int b, int c, int d) { x = a, y = b, time = c, h_f = d; }
};

int r, c, x, y;
char graph[1001][1001];
bool visited[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<Data> q;

int check(int nx, int ny) {
  return 0 <= nx && nx <= r - 1 && 0 <= ny && ny <= c - 1;
}
int escape(int x, int y) {
  return x == 0 || x == r - 1 || y == 0 || y == c - 1;
}
int bfs() {
  // 시간,불(1)사람(0) x, y 순서
  if (escape(x, y))
    return 0;

  q.push({x, y, 0, 0});
  visited[x][y] = true;
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, time = q.front().time,
        h_f = q.front().h_f;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (check(nx, ny) && !visited[nx][ny] && graph[nx][ny] != '#') {
        visited[nx][ny] = true;
        if (h_f == 0 && escape(nx, ny))
          return time + 1;
        q.push({nx, ny, time + 1, h_f});
      }
    }
  }
  return -1;
}
int main() {
  scanf("%d %d", &r, &c);

  for (int i = 0; i < r; ++i) {
    scanf("%s", graph[i]);
    for (int j = 0; j < c; ++j) {
      if (graph[i][j] == 'J') {
        x = i, y = j;
      } else if (graph[i][j] == 'F') {
        q.push({i, j, 0, 1});
        visited[i][j] = true;
      }
    }
  }
  int ans = bfs();

  if (ans == -1)
    printf("IMPOSSIBLE");
  else
    printf("%d", ans + 1);
}
