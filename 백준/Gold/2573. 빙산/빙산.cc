#include <bits/stdc++.h>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

int n, m;
int graph[300][300];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
}

int bfs() {
  int time = 0;

  while (true) {

    bool cnt = false;
    bool visited[300][300] = {};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        if (graph[i][j] > 0 && !visited[i][j]) {
          if (cnt)
            return time;
          else
            cnt = true;

          visited[i][j] = true;
          deque<pair<int, int>> dq;
          deque<pair<int, pair<int, int>>> melt;
          dq.push_back(make_pair(i, j));
          // 빙산 탐색
          while (!dq.empty()) {
            int x = dq.front().first, y = dq.front().second;
            dq.pop_front();
            int sea = 0;
            for (int k = 0; k < 4; ++k) {
              int nx = x + dx[k];
              int ny = y + dy[k];
              if (check(nx, ny) && !visited[nx][ny]) {
                if (graph[nx][ny] > 0) {
                  visited[nx][ny] = true;
                  dq.push_back(make_pair(nx, ny));
                } else
                  ++sea;
              }
            }
            if (sea)
              melt.push_back(make_pair(sea, make_pair(x, y)));
          }
          // 빙산 녹이기
          for (int p = 0, size = melt.size(); p < size; ++p) {
            int sea = melt[p].first, x = melt[p].second.first,
                y = melt[p].second.second;
            graph[x][y] = max(0, graph[x][y] - sea);
          }
        }
    }
    if (!cnt)
      break;
    ++time;
  }
  return 0;
}

int main() {
  FIO;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> graph[i][j];
  }
  cout << bfs();
}