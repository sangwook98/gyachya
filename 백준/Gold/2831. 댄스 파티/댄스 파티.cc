#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n, x, j = 0, cnt = 0;
	cin >> n;
	vector<int> mkp;
	vector<int> mkn;
	vector<int> wkp;
	vector<int> wkn;
	for (int i = 0; i != n; i++) {
		cin >> x;
		if (x > 0) mkp.push_back(x);
		else mkn.push_back(-x);
	}
	for (int i = 0; i != n; i++) {
		cin >> x;
		if (x > 0) wkp.push_back(x);
		else wkn.push_back(-x);
	}
	sort(mkp.begin(), mkp.end(), greater<int>());
	sort(mkn.begin(), mkn.end(), greater<int>());
	sort(wkp.begin(), wkp.end(), greater<int>());
	sort(wkn.begin(), wkn.end(), greater<int>());

	for (int i = 0; i != mkp.size() && j != wkn.size(); i++) {
		if (mkp[i] < wkn[j]) {
			cnt++;
			j++;
		}
	}
	j = 0;
	for (int i = 0; i != wkp.size() && j != mkn.size(); i++) {
		if (wkp[i] < mkn[j]) {
			cnt++;
			j++;
		}
	}
	cout << cnt;
	return 0;
}