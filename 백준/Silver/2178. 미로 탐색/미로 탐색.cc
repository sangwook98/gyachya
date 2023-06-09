#include <deque>
#include <iostream>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

typedef pair<int, int> pii;

int n, m, answer;
char graph[101][101];
deque<pair<int, int>> dq;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
}

int main() {
  FIO;
  cin >> n >> m;
  int distance[101][101];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      distance[i][j] = 10000;
  }

  for (int i = 0; i < n; ++i)
    cin >> graph[i];

  dq.push_back(make_pair(0, 0));
  distance[0][0] = 1;

  while (!dq.empty()) {
    int x = dq.front().first, y = dq.front().second;
    dq.pop_front();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (check(nx, ny) && graph[nx][ny] == 49 &&
          distance[nx][ny] > distance[x][y] + 1) {
        distance[nx][ny] = distance[x][y] + 1;
        dq.push_back(make_pair(nx, ny));
      }
    }
  }
  cout << distance[n - 1][m - 1];
}