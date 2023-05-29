#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, len, damage, C;
ll arr[3000001];
ll psum[3000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> len >> damage;
	cin >> C;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		ll now = psum[i - 1] - psum[max(0, i - len)];
		if (arr[i] <= now + damage) {
			psum[i] = psum[i - 1] + damage;
			continue;
		}
		else {
			if (C) {
				C--;
				psum[i] = psum[i - 1];
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}