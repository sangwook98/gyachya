#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

int n;
long long human, tmp;
pair<int, int> p;
vector<pair<int, int>> v;
int main() {
  FIO;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p.first >> p.second;
    human += p.second;
    v.push_back(p);
  }
  sort(v.begin(), v.end());

  int i = 0;
  for (; i < n; i++) {
    tmp += v[i].second;
    human -= v[i].second;
    if (tmp >= human)
      break;
  }
  cout << v[i].first;
}