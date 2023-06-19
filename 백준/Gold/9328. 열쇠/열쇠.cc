#include <cstdio>
#include <queue>
#include <set>
#include <string>
using namespace std;

int t, h, w;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char graph[102][102];
bool visited[102][102];
bool key[26];
vector<pair<int, int>> v[26];

int check(int nx, int ny) {
  return 0 <= nx && nx <= h + 1 && 0 <= ny && ny <= w + 1;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &h, &w);

    // 초기화
    int answer = 0;
    fill_n(key, 26, false);
    for (int i = 0; i <= h + 1; ++i)
      fill_n(visited[i], w + 2, false);
    //'.'바운더리 만들기
    fill_n(graph[0], w + 2, '.');
    fill_n(graph[h + 1], w + 2, '.');

    for (int i = 1; i <= h; ++i) {
      graph[i][0] = '.';
      scanf("%s", graph[i] + 1);
      graph[i][w + 1] = '.';
    }
    // for (int i = 0; i <= h + 1; ++i)
    //   printf("%s\n", graph[i]);

    // 기존 열쇠 등록
    char s[102];
    scanf("%s", s);
    for (int i = 0; i < 102; ++i) {
      if (s[i] == '\0' || s[0] == '0')
        break;
      else
        key[s[i] - 'a'] = true;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    // BFS 시작
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny) && !visited[nx][ny] && graph[nx][ny] != '*') {
          visited[nx][ny] = true;
          char tmp = graph[nx][ny];

          if (tmp == '.')
            q.push({nx, ny});
          else if (tmp == '$') {
            q.push({nx, ny});
            ++answer;
          } else if ('A' <= tmp && tmp <= 'Z') {
            if (key[tmp - 'A'])
              q.push({nx, ny});
            else
              v[tmp - 'A'].push_back({nx, ny});
          } else if ('a' <= tmp && tmp <= 'z') {
            key[tmp - 'a'] = true;
            while (!v[tmp - 'a'].empty()) {
              int a = v[tmp - 'a'].back().first, b = v[tmp - 'a'].back().second;
              v[tmp - 'a'].pop_back();
              q.push({a, b});
            }
            q.push({nx, ny});
          }
        }
      }
    }
    printf("%d\n", answer);
    for (int i = 0; i < 26; ++i)
      v[i].clear();
  }

  return 0;
}