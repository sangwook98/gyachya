#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

int n, m, d, s;
int A[51][51];
bool visited[51][51];
vector<pair<int, int>> clouds;
vector<pair<int, int>> new_clouds;

int dx[8] = { 0,-1,-1,-1,0,1,1,1};
int dy[8] = { -1,-1,0,1,1,1,0,-1};


void init() {
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], n, false);
	}
	new_clouds.clear();
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	clouds = { {n - 1,0},{n - 1,1},{n - 2,0},{n - 2,1} };

	while (m--) {
		scanf("%d %d", &d, &s);
		init();
		d--;
		// 이동 후 비내리기
		for (int i = 0; i < clouds.size(); i++) {
			int x = clouds[i].first, y = clouds[i].second;
			int nx = (x + s%n*dx[d]+ n)%n;
			int ny = (y + s%n*dy[d] + n)%n;
			A[nx][ny]++;
			new_clouds.push_back({ nx,ny });
			visited[nx][ny] = true;
		}
		clouds.clear();
		// 물 복사 버그
		for (int i = 0; i < new_clouds.size(); i++) {
			int x = new_clouds[i].first, y = new_clouds[i].second;
			for (int k = 1; k < 8; k += 2) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1 && A[nx][ny]) {
					A[x][y]++;
				}
			}
		}

		//구름 생성
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
	
				if (!visited[x][y] && 2 <= A[x][y]) {
					clouds.push_back({ x,y });
					A[x][y] -= 2;
				}

			}
		}
	}
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += A[i][j];
		}
	}
	printf("%lld", answer);

	return 0;
}