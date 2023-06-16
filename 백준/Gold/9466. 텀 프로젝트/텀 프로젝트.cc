#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int t, n;
int child[100001];
int count[100001];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int answer = 0;
    fill_n(count, n + 1, 0);
    queue<int> q;
    for (int i = 1; i < n + 1; ++i) {
      scanf("%d", &child[i]);
      ++count[child[i]];
    }
    for (int i = 1; i < n + 1; ++i) {
      if (count[i] == 0) {
        q.push(i);
        ++answer;
      }
    }

    while (!q.empty()) {
      int a = q.front();
      q.pop();
      --count[child[a]];
      if (count[child[a]] == 0) {
        q.push(child[a]);
        ++answer;
      }
    }
    printf("%d", answer);
    if (t)
      printf("\n");
  }
}
