#include <cstdio>
#include <queue>
#include <string>
using namespace std;
struct Node {
  int x, y, cnt;
  Node(int a, int b, int c) { x = a, y = b, cnt = c; }
};
int INF{40001};

int k, w, h;
int graph[201][201];
int dis[201][201][31];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int hor_dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hor_dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int check(int nx, int ny) {
  return 0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1;
}

int main() {
  scanf("%d %d %d", &k, &w, &h);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf("%d", &graph[i][j]);
      fill_n(dis[i][j], k + 1, INF);
    }
  }
  fill_n(dis[0][0], k + 1, 0);

  queue<Node> q;
  q.push({0, 0, k});

  while (!q.empty()) {
    int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
    q.pop();
    if (x == h - 1 && y == w - 1)
      break;

    // 원숭이처럼 이동
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k], ny = y + dy[k];
      if (check(nx, ny) && graph[nx][ny] == 0 &&
          dis[nx][ny][cnt] > dis[x][y][cnt] + 1) {
        dis[nx][ny][cnt] = dis[x][y][cnt] + 1;
        q.push({nx, ny, cnt});
      }
    }
    // 말처럼 이동
    if (cnt > 0) {
      for (int k = 0; k < 8; ++k) {
        int nx = x + hor_dx[k], ny = y + hor_dy[k];
        if (check(nx, ny) && graph[nx][ny] == 0 &&
            dis[nx][ny][cnt - 1] > dis[x][y][cnt] + 1) {
          dis[nx][ny][cnt - 1] = dis[x][y][cnt] + 1;
          q.push({nx, ny, cnt - 1});
        }
      }
    }
  }

  int answer = INF;
  for (int i = 0; i <= k; ++i) {
    if (answer > dis[h - 1][w - 1][i])
      answer = dis[h - 1][w - 1][i];
  }
  answer = answer == INF ? -1 : answer;
  printf("%d", answer);

  return 0;
}