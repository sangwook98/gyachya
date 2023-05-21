#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;
int arr[10], n;
int main()
{
    int n;
    scanf("%d", &n);

    while (n)
    {
        arr[n % 10]++;
        n /= 10;
    }
    for (int i = 9; i >= 0; i--)
    {
        for (; arr[i] > 0; arr[i]--)
            printf("%d", i);
    }
    return 0;
}