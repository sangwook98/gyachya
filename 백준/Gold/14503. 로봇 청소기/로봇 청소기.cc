#include <bits/stdc++.h>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

int n, m, x, y, heading, answer;
int graph[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
}

int main() {
  FIO;
  cin >> n >> m >> x >> y >> heading;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> graph[i][j];
    }
  }

  while (true) {
    bool cnt = false;
    // cout << answer << " " << x << " " << y << "\n";
    if (graph[x][y] == 0) {
      graph[x][y] = 2;
      answer++;
    }

    for (int i = 3; i >= 0; --i) {
      int nx = x + dx[(heading + i) % 4];
      int ny = y + dy[(heading + i) % 4];
      if (check(nx, ny) && graph[nx][ny] == 0) {
        heading = (heading + i) % 4;
        x = nx, y = ny, cnt = true;
        break;
      }
    }
    // 후진하는 경우
    if (!cnt) {
      int nx = x + dx[(heading + 2) % 4];
      int ny = y + dy[(heading + 2) % 4];
      if (check(nx, ny) && graph[nx][ny] != 1) {
        x = nx, y = ny;
      } else
        break;
    }
  }
  cout << answer;
}