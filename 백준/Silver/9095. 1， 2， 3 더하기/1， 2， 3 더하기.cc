#include <cstdio>
#include <queue>
#include <string>
using namespace std;
int t, n;
int arr[11];
int main() {
  arr[1] = 1, arr[2] = 2, arr[3] = 4;
  for (int i = 4; i <= 10; ++i)
    arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", arr[n]);
  }
  return 0;
}