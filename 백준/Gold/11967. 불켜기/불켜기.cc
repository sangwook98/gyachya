#include <cstdio>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n, m, x, y, a, b, answer;
vector<pair<int, int>> light[101][101];
bool visited[101][101];
bool switc[101][101];
set<pair<int, int>> s;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int check(int nx, int ny) { return 1 <= nx && nx <= n && 1 <= ny && ny <= n; }

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d %d", &x, &y, &a, &b);
    light[x][y].push_back({a, b});
  }

  queue<pair<int, int>> q;
  q.push({1, 1});
  visited[1][1] = true;
  switc[1][1] = true;

  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    // 불 키기
    for (int i = 0; i < light[x][y].size(); ++i) {
      int a = light[x][y][i].first, b = light[x][y][i].second;
      if (!switc[a][b]) {
        switc[a][b] = true;
        ++answer;
        if (s.find({a, b}) != s.end())
          q.push({a, b});
      }
    }
    // 갈 수 있는 곳 set에 넣기
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (check(nx, ny) && !visited[nx][ny]) {
        visited[nx][ny] = true;
        if (switc[nx][ny]) {
          q.push({nx, ny});
        } else {
          s.insert({nx, ny});
        }
      }
    }
  }
  printf("%d", answer + 1);
  return 0;
}