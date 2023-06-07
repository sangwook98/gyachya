#include <bits/stdc++.h>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

int t, n, sx, sy, ex, ey;
pair<int, int> store[100];
int main() {
  FIO;
  cin >> t;
  while (t--) {
    bool visited[100] = {false};
    string answer = "sad";
    deque<pair<int, int>> dq;

    cin >> n >> sx >> sy;
    for (int i = 0; i < n; ++i) {
      cin >> store[i].first >> store[i].second;
    }
    cin >> ex >> ey;

    dq.push_back(make_pair(sx, sy));
    while (!dq.empty()) {
      int x = dq.front().first, y = dq.front().second;
      dq.pop_front();

      if (abs(ex - x) + abs(ey - y) <= 1000) {
        answer = "happy";
        break;
      }

      for (int i = 0; i < n; ++i) {
        if (!visited[i] &&
            abs(store[i].first - x) + abs(store[i].second - y) <= 1000) {
          visited[i] = true;
          dq.push_back(store[i]);
        }
      }
    }
    cout << answer;
    if (t)
      cout << "\n";
  }
}