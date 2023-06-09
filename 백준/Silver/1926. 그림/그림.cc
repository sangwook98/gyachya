#include <deque>
#include <iostream>
#include <string>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

typedef long long ll;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, count, max_size;
bool graph[501][501];
bool visited[501][501];

int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
}

void bfs() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (graph[i][j] && !visited[i][j]) {
        count++;
        int size = 0;
        visited[i][j] = true;
        deque<pair<int, int>> dq;
        dq.push_back(make_pair(i, j));

        while (!dq.empty()) {
          int x = dq.front().first, y = dq.front().second;
          dq.pop_front(), size++;

          for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (check(nx, ny) && graph[nx][ny] && !visited[nx][ny]) {
              visited[nx][ny] = true;
              dq.push_back(make_pair(nx, ny));
            }
          }
        }
        max_size = max(max_size, size);
      }
    }
  }
}

int main() {
  FIO;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> graph[i][j];
  }

  bfs();

  cout << count << "\n";
  cout << max_size;
}