#include <bits/stdc++.h>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

int r, c, answer;

char Map[10001][501];
int visited[10000][500];
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

int dfs(int x, int y) {

  if (y == c - 1) {
    answer++;
    return 1;
  }

  for (int i = 0; i < 3; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx <= r - 1 && 0 <= ny <= c - 1 && Map[nx][ny] == '.') {

      Map[nx][ny] = 'x';
      if (dfs(nx, ny)) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  FIO;
  cin >> r >> c;
  for (int i = 0; i < r; ++i)
    cin >> Map[i];

  for (int i = 0; i < r; ++i)
    dfs(i, 0);
  cout << answer;
}