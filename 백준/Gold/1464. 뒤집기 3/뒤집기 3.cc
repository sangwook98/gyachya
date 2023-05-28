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
string s, ss;
deque<char> q;
int main() {
  FIO;
  cin >> s;
  q.push_back(s[0]);

  for (int i = 1; i < s.size(); i++) {
    if (s[i] <= q.front())
      q.push_front(s[i]);
    else
      q.push_back(s[i]);
  }
  for (auto i : q)
    ss += i;
  cout << ss;
}