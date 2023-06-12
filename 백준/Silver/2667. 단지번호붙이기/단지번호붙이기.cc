#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
char graph[26][26];
bool visited[26][26];
vector<int> v;

int check(int nx, int ny) {
  return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", &graph[i]);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[i][j] && graph[i][j] == '1') {
        int answer = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
          int x = q.front().first, y = q.front().second;
          q.pop();
          //   printf("%d %d\n", x, y);
          answer++;
          for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (check(nx, ny) && !visited[nx][ny] && graph[nx][ny] == '1') {
              visited[nx][ny] = true;
              q.push({nx, ny});
            }
          }
        }
        v.push_back(answer);
      }
    }
  }
  sort(v.begin(), v.end());
  printf("%d\n", v.size());
  for (auto i : v)
    printf("%d\n", i);
}