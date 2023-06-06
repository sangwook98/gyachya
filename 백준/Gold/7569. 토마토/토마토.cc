#include <bits/stdc++.h>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

int n, m, h, a, answer, tomato;
int graph[102][102][102];
deque<pair<int, pair<int, int>>> dq;
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0}; // 북동남서위아
int dz[6] = {0, 0, 0, 0, -1, 1};

int check(int nx, int ny, int nz) {
  return (nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n - 1 && nz >= 0 &&
          nz <= h - 1);
}

int main() {
  FIO;
  cin >> n >> m >> h;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < n; ++k) {
        cin >> a, graph[i][j][k] = a;
        if (a == 0)
          tomato++;
        else if (a == 1)
          dq.push_back(make_pair(i, make_pair(j, k)));
      }
    }
  }

  while (tomato && !dq.empty()) {
    for (int i = 0, siz = dq.size(); i < siz; ++i) {
      int z = dq.front().first, x = dq.front().second.first,
          y = dq.front().second.second;
      dq.pop_front();
      for (int j = 0; j < 6; ++j) {
        int nx = x + dx[j];
        int ny = y + dy[j];
        int nz = z + dz[j];
        if (check(nx, ny, nz) && graph[nz][nx][ny] == 0) {
          graph[nz][nx][ny] = 1;
          tomato--;
          dq.push_back(make_pair(nz, make_pair(nx, ny)));
        }
      }
    }

    answer++;
  }
  if (tomato)
    cout << -1;
  else
    cout << answer;
}