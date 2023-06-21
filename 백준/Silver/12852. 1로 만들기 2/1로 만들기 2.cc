#include <queue>
#include <stdio.h>
#include <string>
using namespace std;

int arr[1000001];
int parent[1000001];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    arr[i] = arr[i - 1] + 1;
    parent[i] = i - 1;
    if (i % 3 == 0 && arr[i / 3] + 1 < arr[i]) {
      arr[i] = arr[i / 3] + 1;
      parent[i] = i / 3;
    }
    if (i % 2 == 0 && arr[i / 2] + 1 < arr[i]) {
      arr[i] = arr[i / 2] + 1;
      parent[i] = i / 2;
    }
  }
  printf("%d\n", arr[n]);

  while (n != 1) {
    printf("%d ", n);
    n = parent[n];
  }
  printf("1");
  return 0;
}