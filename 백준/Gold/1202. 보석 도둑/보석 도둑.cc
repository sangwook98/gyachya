#include <bits/stdc++.h>
using namespace std;
#define FIO                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
typedef long long ll;

ll answer;
int n, k, m, v, t;
vector<int> weight[1000001];
priority_queue<int> pq;
int main() {
  FIO;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> m >> v, weight[m].push_back(v);
  }
  int arr[k];
  for (int i = 0; i < k; ++i)
    cin >> arr[i];

  sort(arr, arr + k);

  int j = 0, p;
  for (int i = 0; i < k; ++i) {
    p = arr[i];
    for (; j < p + 1; ++j) {
      for (int x = 0; x < weight[j].size(); ++x) {
        pq.push(weight[j][x]);
      }
    }
    if (!pq.empty())
      answer += pq.top(), pq.pop();
  }
  cout << answer;
}