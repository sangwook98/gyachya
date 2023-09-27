#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
// 09:45start
int n, k, a, time;
deque<pair<int, bool>> dq; // 내구도,로봇유무

void robot_down() {
  if (dq[n - 1].second) {
    dq[n - 1].second = false;
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &a);
    dq.push_back({a, false});
  }

  while (true) {
    time++;
    // 컨베이동
    int power = dq.back().first;
    dq.pop_back();
    dq.push_front({power, false});
    robot_down();
    // 로봇들이동
    for (int i = n - 2; i > 0; i--) {
      if (dq[i].second && !dq[i + 1].second && dq[i + 1].first) {
        dq[i].second = false;
        dq[i + 1].second = true;
        dq[i + 1].first--;
      }
      if (i == n - 2)
        robot_down();
    }

    // 로봇 올리기
    if (dq[0].first) {
      dq[0].first--;
      dq[0].second = true;
    }
    // 종료 인지 아닌지 알기
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
      if (dq[i].first == 0)
        cnt++;
    }

    if (cnt >= k)
      break;
  }

  printf("%d", time);
  return 0;
}