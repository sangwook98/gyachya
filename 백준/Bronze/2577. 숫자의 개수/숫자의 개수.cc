#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string s = to_string(a * b * c);
    int arr[10] = {};

    for (int i = 0; i < s.size(); i++)
    {
        int d = s[i] - '0';
        arr[d]++;
    }

    for (int j = 0; j < 10; j++)
    {
        cout << arr[j] << "\n";
    }

    return 0;
}