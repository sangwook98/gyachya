#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int n, m, t, x, d, k;
int graph[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };



void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



bool check(int nx, int ny) {
	return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
}

void turn(int index, int dir, int d) {
	int tmp[51];
	for (int i = 0; i < m; i++) {
		tmp[i] = graph[index][i];
	}

	if (dir == 1) {//반시계
		for (int i = 0; i < m; i++) {
			graph[index][(i + d + m) % m] = tmp[i];
		}
	}
	else {//시계
		for (int i = 0; i < m; i++) {
			graph[index][(i - d + m) % m] = tmp[i];
		}
	}
}

int main() {
	scanf("%d %d %d", &n,&m,&t);

	for (int i = 0; i < n; i++) {
		scanf("%d", &graph[i][0]);
		for (int j = m-1; j >= 1; j--) {
			scanf("%d", &graph[i][j]);
		}
	}
	//show();
	while (t--) {
		scanf("%d %d %d", &x, &d, &k);

		for (int i = x; i <= n; i += x) {
			turn(i - 1, d, k);
		}

		//근접 확인
		set<pair<int, int>> s = {};
		int total = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 0)
					continue;
				else {
					total += graph[i][j];
					cnt++;
				}

				for (int k = 0; k < 4; k++) {
					if ((i == 0 && k == 0) || (i == n - 1 && k == 2)) {
						continue;
					}
					int nx = i + dx[k];
					int ny = (j + dy[k] + m)%m;
					if (graph[i][j] == graph[nx][ny]) {
						s.insert({ nx,ny });
					}

				}
				
			}
		}
		//set가 비어있으면 평균 계산, 아니면 숫자 없애기
		if (s.size() == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (graph[i][j]) {
						if (graph[i][j] < (float)total / cnt) {
							graph[i][j]++;
						}
						else if (graph[i][j] > (float)total / cnt) {
							graph[i][j]--;
						}
					}
				}
			}
		}
		else {
			for (auto it = s.begin(); it != s.end(); it++) {
				pair<int, int> p = *it;
				graph[p.first][p.second] = 0;
			}

		}
		//show();
	}
	//총합 계산
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer += graph[i][j];
		}
	}
	printf("%d", answer);
	return 0;
}