#include <bits/stdc++.h>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

struct sel {
  int box, start, end;
};
int compare(const sel &a, const sel &b) {
  if (a.end == b.end) {
    return a.start > b.start;
  } else
    return a.end > b.end;
}

int n, c, m, a, b, d;
ll answer;
int arr[2001];
int main() {
  FIO;
  cin >> n >> c >> m;
  sel sv[m];
  sel s;
  for (int i = 0; i < m; ++i) {
    cin >> s.start >> s.end >> s.box;
    sv[i] = s;
  }

  sort(sv, sv + m, compare);

  // for (auto i : sv)
  //   cout << i.dis << ' ' << i.box << ' ' << i.start << "\n";

  for (int i = 0; i < m; ++i) {
    int mini = 100000;
    for (int j = sv[i].start; j < sv[i].end; ++j) {
      mini = min({mini, c - arr[j], sv[i].box});
    }
    answer += mini;
    for (int j = sv[i].start; j < sv[i].end; ++j) {
      arr[j] += mini;
    }
    // for (int i = 0; i < 30; ++i)
    //   cout << arr[i] << " ";
    // cout << "\n";
  }
  cout << answer;
}