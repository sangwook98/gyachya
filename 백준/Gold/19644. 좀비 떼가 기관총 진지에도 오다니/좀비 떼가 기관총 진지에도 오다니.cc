#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

int l, m_l, m_k, c, t, one, zero;
int main() {
  FIO;
  cin >> l >> m_l >> m_k >> c;

  deque<int> dq, shot_dq(m_l - 1, 0);

  for (int i = 0; i < l; i++) {
    cin >> t, dq.push_back(t);
  }
  // for (int i = 0; i < m_l - 1; i++)
  //   shot_dq.push_back(0);
  zero = m_l - 1, one = 0;

  while (!dq.empty()) {
    int zombie = dq.front();

    if (zombie <= one * m_k + m_k)
      dq.pop_front(), shot_dq.push_back(1), one++;
    else {
      if (c) {
        c--, dq.pop_front(), shot_dq.push_back(0), zero++;
      } else
        break;
    }

    if (shot_dq.front() == 1)
      one--;
    else
      zero--;
    shot_dq.pop_front();
  }

  string answer = dq.empty() ? "YES" : "NO";
  cout << answer;
}