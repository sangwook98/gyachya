#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;
int n, t;
ll answer;
vector<int> m, p;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t > 0)
      p.push_back(t);
    else
      m.push_back(t);
  }
  sort(p.begin(), p.end());
  sort(m.begin(), m.end(), greater<int>());

  long long a, b;
  while (!p.empty()) {
    a = p.back(), p.pop_back();
    if (p.size() == 0) {
      answer += a;
    } else {
      b = p.back(), p.pop_back();
      if (a == 1 || b == 1)
        answer += a + b;
      else
        answer += a * b;
    }
  }
  while (!m.empty()) {
    a = m.back(), m.pop_back();
    if (m.size() == 0) {
      answer += a;
    } else {
      b = m.back(), m.pop_back();
      answer += a * b;
    }
  }
  cout << answer;
}