#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
// 13:43 start
struct Node {
  int x, y;
  Node(int a, int b) { x = a, y = b; }
};

int n, m, answer{100000000};
int graph[51][51];
vector<Node> chicken;
vector<Node> house;
deque<Node> dq;

void dfs(int index, int depth) {
  if (depth == m) {
    int total = 0;
    for (int i = 0; i < house.size(); i++) {
      int dis = 100000000;
      for (int j = 0; j < dq.size(); j++) {
        dis = min(dis, abs(dq[j].x - house[i].x) + abs(dq[j].y - house[i].y));
        // printf("%d ", dis);
      }
      total += dis;
    }
    // printf("%d\n", answer);
    answer = min(answer, total);
    return;
  }

  for (int i = index; i < chicken.size(); i++) {
    int x = chicken[i].x, y = chicken[i].y;
    dq.push_back({x, y});
    dfs(i + 1, depth + 1);
    dq.pop_back();
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j] == 1)
        house.push_back({i, j});
      else if (graph[i][j] == 2)
        chicken.push_back({i, j});
    }
  }
  dfs(0, 0);
  // dfs로 치킨집 선정
  // 마지막depth에서 짧은 거리 선정.
  printf("%d", answer);
  return 0;
}
