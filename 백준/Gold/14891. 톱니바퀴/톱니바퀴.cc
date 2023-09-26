#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
// 09:51start
int k, a, num, dir;
deque<int> dq[4];

int main() {
  // 바퀴 정보 deque에 담기
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      scanf("%1d", &a);
      dq[i].push_back(a);
    }
  }
  queue<pair<int, int>> q;
  scanf("%d", &k);
  while (k--) {
    scanf("%d %d", &num, &dir);
    num--;
    q.push({num, dir});
    bool visited[4] = {false};
    int do_turn[4] = {0};
    visited[num] = true;
    do_turn[num] = dir;

    // 돌려지는 바퀴 큐에 넣기
    while (!q.empty()) {
      int a = q.front().first, b = q.front().second;
      q.pop();
      if (0 <= a - 1 && !visited[a - 1]) {
        visited[a - 1] = true;
        if (dq[a - 1][2] != dq[a][6]) {
          do_turn[a - 1] = -b;
          q.push({a - 1, -b});
        }
      }

      if (a + 1 <= 3 && !visited[a + 1]) {
        visited[a + 1] = true;
        if (dq[a][2] != dq[a + 1][6]) {
          do_turn[a + 1] = -b;
          q.push({a + 1, -b});
        }
      }
    }
    // 바퀴 돌리기
    for (int i = 0; i < 4; i++) {
      if (do_turn[i] == -1) {
        int a = dq[i].front();
        dq[i].pop_front();
        dq[i].push_back(a);
      } else if (do_turn[i] == 1) {
        int a = dq[i].back();
        dq[i].pop_back();
        dq[i].push_front(a);
      }
    }
  }
  int answer = 0;
  if (dq[0][0] == 1)
    answer += 1;
  if (dq[1][0] == 1)
    answer += 2;
  if (dq[2][0] == 1)
    answer += 4;
  if (dq[3][0] == 1)
    answer += 8;

  printf("%d", answer);

  return 0;
}