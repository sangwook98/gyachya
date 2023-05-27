#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

int n, t, answer;
vector<int> t_m, s_m, t_w, s_w;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t < 0)
      s_m.push_back(-t);
    else
      t_m.push_back(t);
  }
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t < 0)
      s_w.push_back(-t);
    else
      t_w.push_back(t);
  }

  sort(s_m.begin(), s_m.end());
  sort(t_m.begin(), t_m.end());
  sort(s_w.begin(), s_w.end());
  sort(t_w.begin(), t_w.end());

  int a, b;
  while (!s_m.empty() && !t_w.empty()) {
    a = s_m.back(), s_m.pop_back();
    b = t_w.back(), t_w.pop_back();
    if (a > b)
      answer++;
    else
      s_m.push_back(a);
  }
  while (!s_w.empty() && !t_m.empty()) {
    a = t_m.back(), t_m.pop_back();
    b = s_w.back(), s_w.pop_back();
    if (a < b)
      answer++;
    else
      s_w.push_back(b);
  }
  cout << answer;
}