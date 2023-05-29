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
string num, bomb;

int main() {
  FIO;
  cin >> t;
  while (t--) {
    cin >> n >> num >> bomb;
    int answer = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (num[i] != '0' && num[i + 1] != '0') {
          num[i]--, num[i + 1]--, answer++;
        }
      } else if (i == n - 1) {
        if (num[i - 1] != '0' && num[i] != '0') {
          num[i - 1]--, num[i]--, answer++;
        }
      } else {
        if (num[i - 1] != '0' && num[i] != '0' && num[i + 1] != '0') {
          num[i - 1]--, num[i]--, num[i + 1]--, answer++;
        }
      }
    }
    cout << answer << "\n";
  }
}