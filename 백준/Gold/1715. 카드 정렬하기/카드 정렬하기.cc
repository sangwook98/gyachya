#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

int n, t;
ll answer;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
  FIO;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    q.push(t);
  }
  int a, b;
  while (!(q.size() == 1)) {
    a = q.top(), q.pop();
    b = q.top(), q.pop();
    answer += a + b;
    q.push(a + b);
  }
  cout << answer;
}