#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
#define INF 1000000 
#pragma warning(disable:4996)

using namespace std;

//13:21start
//1 ≤ N ≤ 20 ,1 ≤ M ≤ 5
//조건들
//1. 블럭은 검은색, 무지개, 일반블럭이 있다.
//1.1 검은색은 -1, 무지개는 0, 일반은 m가지 색상번호
//2. 블록 그룹은 연결된 블록의 집합이다.
//2.1 그룹에는 일반 블록이 적어도 1개 있어야 한다.
//2.2 일반 블록의 색은 모두 같아야 한다.
//2.3 그룹에 속한 블록의 개수는 2보다 크거나 같아야한다.
//2.4 한 그룹은 한 덩어리여야 한다.
//2.5 그룹의 기준 블록은 무지개 블록이 아니여야 하고 행열, 가장작은 블럭이여야한다.
// 
//3 오토플레이 기능은 다음과 같은 과정이 블록 그룹에 존재하는동안 계속 반복
//3.1 크기가 가장 큰 블록을 찾는다.
//3.2 크기가 같은게 많다면 무지개 블록의 수가 많은것, 그런 블록도 여러개면 기준블록 행열이 큰것.
//4. 3에서 찾은 블록 그룹의 모든 블록을 제거. 블록의 수가 B면 B^2의 점수 획득
//5. 격자에 중력이 작용한다.
//5.1 중력이 작용할 때 검은색 블록을 제외한 모든블럭이 행이 큰 칸으로 이동한다.
//6. 격자가 90도 반시계방향으로 회전한다.
//7. 다시 격자에 중력이 작용한다.

//문제 풀이 생각
//1. bfs를 이용해 최대그룹 찾기
//1.1 한번 찾은 그룹은 x,y 다기억해야 함. 벡터 생성, 그리고 bfs 전체 돌고 마지막에 최대 벡터 좌표들 빈공간 -2로 만들기. 점수도 얻기
//1.2 무지개 많을 수록 높은점수
//2. 중력 함수 만들기
//3. 반시계 90도 회전 함수 만들기
//4 그룹 크기가 모두 1일때까지 반복.


//변수설정
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int graph[21][21];
bool visited[21][21];

int n, m, answer;
bool tmp{ true };


void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool check(int nx, int ny) {
	return 0 <= nx && nx <= n-1 && 0 <= ny && ny <= n-1;
}
void init() {
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], n, false);
	}

}
void bfs() {
	init();
	vector<pair<int,int>> best_v;
	int best_rainbow = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//기준블록은 일반색깔이어야함.
			if (!visited[i][j] && graph[i][j] > 0) {
				visited[i][j] = true;
				int color = graph[i][j];
				int rainbow = 0;
				//무지개블록은 visit 풀어줘야 함!!
				queue<pair<int, int>> q;
				vector< pair<int, int>> v;
				vector< pair<int, int>> zero;

				v.push_back({ i,j });
				q.push({ i,j });


				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						//2.2 일반 블록의 색은 모두 같아야 한다.
						//2.3 그룹에 속한 블록의 개수는 2보다 크거나 같아야한다.
						//2.4 무지개블록이어야한다.
						if (check(nx, ny) && !visited[nx][ny] && (graph[nx][ny] == color || graph[nx][ny] == 0)) {
							if (graph[nx][ny] == 0) {
								zero.push_back({ nx,ny });
								rainbow++;
							}
							q.push({ nx,ny });
							v.push_back({ nx,ny });
							visited[nx][ny] = true;
						}
					}
				}

				if (v.size() == 1)
					continue;

				if (v.size() > best_v.size()) {
					best_v = v, best_rainbow = rainbow;
				}
				else if (v.size() == best_v.size()) {
					if (rainbow >= best_rainbow) {
						best_v = v, best_rainbow = rainbow;
					}
				}

				for (int p = 0; p < zero.size(); p++) {
					visited[zero[p].first][zero[p].second] = false;
				}

			}
		}
	}
	if (best_v.size() == 0) {
		tmp = false;
		return;
	}
	//블럭 점수 얻기
	answer += best_v.size() * best_v.size();
	//블럭들 없애기
	for (int i = 0; i < best_v.size(); i++) {
		int x = best_v[i].first, y = best_v[i].second;
		graph[x][y] = -2;
	}



	return;
}

void gravity() {
	for (int j = 0; j < n; j++) {
		vector<int> v;
		for (int i = n - 1; i >= 0; i--) {
			if (graph[i][j] >= 0) {
				v.push_back(graph[i][j]);
			}
			else if (graph[i][j] == -2) {
				continue;
			}
			else if (graph[i][j] == -1) {
				while (v.size() != n - i-1) {
					v.push_back(-2);
				}
				v.push_back(-1);
			}
		}
		while (v.size() < n) {
			v.push_back(-2);
		}

		for (int i = n - 1; i >= 0; i--) {
			graph[i][j] = v[n-i-1];
		}
	}
}

void r_clockwise() {
	int tmp[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[n-1 - j][i] = graph[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = tmp[i][j];
		}
	}
}

void solution() {
	while (tmp) {
		//1. bfs를 이용해 최대그룹 찾기
		//1.1 한번 찾은 그룹은 x,y 다기억해야 함. 벡터 생성, 그리고 bfs 전체 돌고 마지막에 최대 벡터 좌표들 빈공간 -2로 만들기. 점수도 얻기
		//1.2 무지개 많을 수록 높은점수
		//show();
		int tmpp = answer;
		bfs();
		if (!tmp)
			return;
		//printf("%d %d\n",answer, answer-tmpp);
		//show();
		//5. 격자에 중력이 작용한다.
		//5.1 중력이 작용할 때 검은색 블록을 제외한 모든블럭이 행이 큰 칸으로 이동한다.
		gravity();
		//show();
		//6. 격자가 90도 반시계방향으로 회전한다.
		r_clockwise();
		//show();
		//7. 다시 격자에 중력이 작용한다.
		gravity();
		//show();
		//printf("----------------\n");
	}

}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	solution();
	printf("%d", answer);

	return 0;
}