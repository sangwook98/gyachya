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
  answer.push_back(number[0]);

  for (int i = 1; i < n; i++) {
    while (!answer.empty() && answer.back() < number[i] && k > 0) {
      answer.pop_back(), k--;
    }

    answer.push_back(number[i]);
  }
  while (k--)
    answer.pop_back();

  cout << answer;
}