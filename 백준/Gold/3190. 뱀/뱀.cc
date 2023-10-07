#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int n, k, a, b, l, x;
int hx, hy, tx, ty;
int dir{ 1 };
char c;
int graph[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, char>> q;
deque<pair<int, int>> snake;

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		graph[a-1][b-1] = 1;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &x, &c);
		q.push({ x,c });
	}
	graph[hx][hy] = 2;
	snake = { {hx,hy} };
	int time = 0;
	while (++time) {
		//뱀 이동
		hx = snake.front().first, hy = snake.front().second;
		tx = snake.back().first, ty = snake.back().second;
		int nhx = hx + dx[dir];
		int nhy = hy + dy[dir];
		if (0 <= nhx && nhx <= n - 1 && 0 <= nhy && nhy <= n - 1 && graph[nhx][nhy] <= 1) {
			if (graph[nhx][nhy] == 0) {
				graph[tx][ty] = 0;
				snake.pop_back();
			}

			snake.push_front({ nhx,nhy });
			graph[nhx][nhy] = 2;
		}
		else {
			break;
		}
		if (!q.empty() && time == q.front().first) {
			if (q.front().second == 'D') {
				dir = (dir + 1 + 4) % 4;
			}
			else {
				dir = (dir - 1 + 4) % 4;
			}
			q.pop();
		}
		//show();
		
	}
	printf("%d", time);
	return 0;
}