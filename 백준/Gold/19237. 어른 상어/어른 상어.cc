#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

struct Node {
	int x, y, dir;
};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

pair<int, int> graph[21][21];
pair<int,int> smell[21][21];
pair<int, int> pos[401];
int dirs[401][4][4];
int n, m, k;

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("(%d %d) ",graph[i][j].first, graph[i][j].second);
		}
		printf("\n");
	}
	printf("\n");
}
void show1() {
	printf("smell\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("(%d %d) ", smell[i][j].first, smell[i][j].second);
		}
		printf("\n");
	}
	printf("\n");
}


bool check(int nx, int ny) {
	return 0 <= nx && nx <= n-1 && 0 <= ny && ny <= n-1;
}

Node where_to_go(int x, int y, int dir, int num) {
	int back_dir = dir % 2 ? dir - 1 : dir + 1;

	int rear_x = x + dx[back_dir];
	int rear_y = y + dy[back_dir];

	Node my_smell = { -1,-1,-1 };

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[dirs[num][dir][i]];
		int ny = y + dy[dirs[num][dir][i]];
		//printf("%d %d %d %d %d\n", num,dir, dirs[num][dir][i],nx, ny);
		if (!check(nx, ny))
			continue;
		//냄새 없는 칸 발견!
		if (smell[nx][ny].second == 0) {
			return { nx,ny,dirs[num][dir][i] };
		}
		//내 냄새가 있는 칸 발견!
		if (my_smell.x == -1 && smell[nx][ny].first == num && smell[nx][ny].second != 0) {
			my_smell = { nx,ny,dirs[num][dir][i] };
		}
	}
	if (my_smell.x != -1) {
		return my_smell;
	}

	return { rear_x, rear_y, back_dir };
}

void smell_del() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (smell[i][j].second > 1) {
				smell[i][j].second--;
			}
			else if (smell[i][j].second == 1) {
				smell[i][j].second--;
				smell[i][j].first = 0;
			}
		}
	}
}

void init(pair<int, int> tmp_graph[21][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_graph[i][j] = { -1,-1 };
		}
	}
}
void finish(pair<int, int> tmp_graph[21][21], pair<int, int> graph[21][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = tmp_graph[i][j];
		}
	}
}

int solution() {

	int time = 0;

	while (time <= 1000) {

		pair<int, int> tmp_graph[21][21];
		init(tmp_graph);

		vector<Node> will_smell;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j].first != -1) {
					cnt++;
					int num = graph[i][j].first;
					int dir = graph[i][j].second;

					//이동할 곳 찾기
					Node next = where_to_go(i, j, dir, num);

					if (tmp_graph[next.x][next.y].first == -1 || tmp_graph[next.x][next.y].first > num) {
						tmp_graph[next.x][next.y] = { num,next.dir };
						will_smell.push_back({ next.x,next.y,num });

					}

				}
			}
		}
		smell_del();
		for (auto i : will_smell) {
			smell[i.x][i.y] = { i.dir,k };
		}

		
		if (cnt == 1)
			return time;
		
		finish(tmp_graph,graph);
		//printf("---\n");
		//show();
		//show1();
		time++;
		
	}

	if (time >= 1001) {
		time = -1;
	}
	return time;
}


int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d ", &graph[i][j].first);
			if (graph[i][j].first) {
				graph[i][j].first--;
				pos[graph[i][j].first] = { i,j };
				smell[i][j] = { graph[i][j].first, k };
			}
			else {
				graph[i][j].first = -1;
			}
		}
	}
	int a;
	for (int i = 0; i < m; i++) {
		scanf("%d ", &a);
		int x = pos[i].first, y = pos[i].second;
		graph[x][y].second = a-1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				scanf("%d ", &a);
				dirs[i][j][k] = a - 1;
			}
		}
	}
	
	//show();
	printf("%d", solution());

	return 0;
}