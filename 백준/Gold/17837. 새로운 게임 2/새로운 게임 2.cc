#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

struct Node {
	int x, y, dir;
};

int n, k, a,b,c;
int graph[13][13];
vector<int> v[13][13];
Node node[11];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		}
		printf("\n");
	}
	printf("\n");
}



bool check(int nx, int ny) {
	return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1;
}

pair<int, int> white(int x, int y, int nx, int ny, int index) {
	
	auto it = find(v[x][y].begin(),v[x][y].end(),index);
	int num = it - v[x][y].begin();
	int size = v[x][y].size();

	for (int i = num; i < size; i++) {
		v[nx][ny].push_back(v[x][y][i]);
		node[v[x][y][i]].x = nx, node[v[x][y][i]].y = ny;
	}
	for (int i = num; i < size; i++) {
		v[x][y].pop_back();
	}

	return { nx,ny };
}

pair<int, int> red(int x, int y, int nx, int ny, int index) {

	white(x, y, nx, ny, index);


	auto it = find(v[nx][ny].begin(), v[nx][ny].end(), index);
	reverse(it, v[nx][ny].end());
	int size = v[nx][ny].size();

	return { nx,ny };
}

pair<int, int> blue(int x, int y, int nx, int ny, int index) {

	int dir = node[index].dir;
	int new_dir = dir % 2 ? dir - 1 : dir + 1;

	node[index].dir = new_dir;
	int nnx = x + dx[new_dir];
	int nny = y + dy[new_dir];

	if (!check(nnx, nny) || graph[nnx][nny] == 2) {
		return { -1,-1 };
	}
	else if (graph[nnx][nny] == 0) {
		white(x, y, nnx, nny, index);
	}
	else if (graph[nnx][nny] == 1) {
		red(x, y, nnx, nny, index);
	}

	return { nnx,nny };
}

int solution() {
	int time = 0;
	while (++time < 1001) {
		for (int i = 0; i < k; i++) {
			int x = node[i].x, y = node[i].y, dir = node[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			pair<int, int> p;
			if (!check(nx, ny)) {
				p = blue(x, y, nx, ny, i);
			}
			else if (graph[nx][ny] == 0) {
				p = white(x, y, nx, ny, i);
			}
			else if (graph[nx][ny] == 1) {
				p = red(x, y, nx, ny, i);
			}
			else if (graph[nx][ny] == 2) {
				p = blue(x, y, nx, ny, i);
			}

			int d = p.first, e = p.second;
			if (d == -1 && e == -1) {
				continue;
			}
			else {
				if (v[d][e].size() >= 4)
					return time;
			}

			

		}
		//printf("--------------\n");

	}
	return -1;
}

int main() {
	scanf("%d %d", &n,&k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		node[i] = { a - 1,b - 1,c - 1 };
		v[a - 1][b - 1].push_back(i);
	}

	printf("%d", solution());

	return 0;
}