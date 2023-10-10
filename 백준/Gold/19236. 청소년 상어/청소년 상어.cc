#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int dx[8] = { -1,-1,0,1,1,1,0,-1};
int dy[8] = { 0,-1,-1,-1,0,1,1,1};

pair<int,int> graph[4][4];
int num, dir, answer;

void show(pair<int, int> graph[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("(%d %d) ",graph[i][j].first, graph[i][j].second);
		}
		printf("\n");
	}
	printf("\n");
}


bool check(int nx, int ny) {
	return 0 <= nx && nx <= 3 && 0 <= ny && ny <= 3;
}

pair<int, int> find_fish(pair<int, int> graph[4][4], int num) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (graph[i][j].first == num)
				return{ i,j };
		}
	}
	return { -1,-1 };
}

void fish_move(pair<int, int> graph[4][4], int sharkX, int sharkY) {
	for (int i = 0; i < 16; i++) {
		pair<int, int> fish = find_fish(graph, i);
		int x = fish.first, y = fish.second;
		int dir = graph[x][y].second;
		if (x == -1 && y == -1)
			continue;

		for (int j = 0; j < 8; j++) {
			int nx = x + dx[(dir + j) % 8];
			int ny = y + dy[(dir + j) % 8];
			if (check(nx, ny) && !(nx == sharkX && ny == sharkY)) {
				dir = (dir + j) % 8;
				pair<int, int> tmp = graph[x][y];
				tmp.second = dir;
				graph[x][y] = graph[nx][ny];
				graph[nx][ny] = tmp;
	
				break;
			}
			//printf("%d %d\n", nx, ny);
			
		}
		//printf("%d\n", i);
		//show(graph);
	}
}

void dfs(pair<int,int> graph[4][4],int sharkX,int sharkY, int prev_total) {
	pair<int, int> tmp_graph[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp_graph[i][j] = graph[i][j];
		}
	}

	//sharkEAT
	int fish_num = tmp_graph[sharkX][sharkY].first;
	int total = prev_total + fish_num + 1;

	tmp_graph[sharkX][sharkY].first = -1;
	int dir = tmp_graph[sharkX][sharkY].second;

	//show(tmp_graph);
	fish_move(tmp_graph, sharkX,sharkY);

	//printf("total %d\n\n", total);
	//show(tmp_graph);
	 
	for (int i = 1; i < 4; i++) {
		int nx = sharkX + i * dx[dir];
		int ny = sharkY + i * dy[dir];
		if (check(nx, ny) && tmp_graph[nx][ny].first != -1) {
			dfs(tmp_graph, nx,ny, total);
		}
	}


	answer = max(answer, total);
}


int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d ", &num,&dir);
			num--, dir--;
			graph[i][j] = { num,dir };
		}
	}

	dfs(graph, 0,0,0);

	printf("%d", answer);

	return 0;
}