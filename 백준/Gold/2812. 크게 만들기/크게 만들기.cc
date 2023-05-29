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

string number, answer;
deque<int> dq;
int n, k;
int main() {
  FIO;
  cin >> n >> k >> number;
  dq.push_back(number[0] - '0');
  for (int i = 1; i < n; i++) {
    while (!dq.empty() && dq.back() < number[i] - '0' && k > 0) {
      dq.pop_back(), k--;
    }

    dq.push_back(number[i] - '0');
  }

  while (k--)
    dq.pop_back();

  for (auto i : dq)
    cout << i;
}