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

int check(string num, string bomb, int cnt) {
  if (cnt)
    bomb[0] = '*';
  else
    bomb[0] = '.';

  int siz = num.size();
  int answer = 0;
  for (int i = 0; i < siz; i++) {
    if (i != 0 && i != siz - 1) {
      int count = 0;
      for (int j = i - 1; j < i + 2; j++) {
        if (bomb[j] == '*')
          num[i]--;
      }
      if (num[i] == '0')
        ;
      else if (num[i] == '1')
        bomb[i + 1] = '*';
      else if (num[i] == '2')
        return 0;
    } else if (i == 0) {
      int count = 0;
      for (int j = i; j < i + 2; j++) {
        if (bomb[j] == '*')
          num[i]--;
      }
      if (num[i] == '0')
        ;
      else if (num[i] == '1')
        bomb[i + 1] = '*';
      else if (num[i] == '2')
        return 0;

    } else if (i == siz - 1) {
      int count = 0;
      for (int j = i - 1; j < i + 1; j++) {
        if (bomb[j] == '*')
          num[i]--;
      }
      if (num[i] == '0')
        ;
      else if (num[i] == '1')
        return 0;
      else if (num[i] == '2')
        return 0;
    }
    if (bomb[i] == '*')
      answer++;
  }
  // for (auto i : bomb)
  //   cout << i;
  return answer;
}
int main() {
  FIO;
  cin >> t;
  while (t--) {
    cin >> n >> num >> bomb;
    int answer = 0;
    answer = max(answer, check(num, bomb, 0));
    if (num[0] - '0' > 0)
      answer = max(answer, check(num, bomb, 1));
    cout << answer << "\n";
  }
}