#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct Data {
  int x, y, z;
  Data(int a, int b, int c) { x = a, y = b, z = c; }
};

int dx[6] = {-1, 0, 1, 0, 0, 0}; // 북동남서위아래
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int INF{1000000};
char graph[31][31][31];
int l, r, c;

int check(int nx, int ny, int nz) {
  return 0 <= nx && nx <= r - 1 && 0 <= ny && ny <= c - 1 && 0 <= nz &&
         nz <= l - 1;
}

int main() {
  int distance[31][31][31];
  while (true) {
    scanf("%d %d %d", &l, &r, &c);
    if (l == 0 && r == 0 && c == 0)
      break;
    int sx, sy, sz, ex, ey, ez;

    for (int z = 0; z < l; ++z) {
      for (int x = 0; x < r; ++x) {
        scanf("%s", graph[z][x]);
        for (int y = 0; y < c; ++y) {
          distance[z][x][y] = INF;
          if (graph[z][x][y] == 'S')
            sx = x, sy = y, sz = z;
          else if (graph[z][x][y] == 'E')
            ex = x, ey = y, ez = z;
        }
      }
    }
    distance[sz][sx][sy] = 0;
    queue<Data> q;
    q.push({sx, sy, sz});

    while (!q.empty()) {
      int x = q.front().x, y = q.front().y, z = q.front().z;
      q.pop();
      if (x == ex && y == ey && z == ez) {
        break;
      }
      for (int i = 0; i < 6; ++i) {
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if (check(nx, ny, nz) && distance[nz][nx][ny] > distance[z][x][y] + 1 &&
            graph[nz][nx][ny] != '#') {
          distance[nz][nx][ny] = distance[z][x][y] + 1;
          q.push({nx, ny, nz});
        }
      }
    }
    int ans = distance[ez][ex][ey];
    if (ans == INF)
      printf("Trapped!\n");
    else
      printf("Escaped in %d minute(s).\n", ans);
  }
}