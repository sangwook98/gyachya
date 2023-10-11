#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
#define INF 1000000 
#pragma warning(disable:4996)

using namespace std;

//10:23start
// 2 ≤ N ≤ 20, 1 ≤ M ≤ N2, 1 ≤ 초기 연료 ≤ 500,000

//문제 조건들
//1. 택시는 손님을 도착지로 데리고가면 연료 충전됨.
//2. 연료가 바닥나면 그날 업무 종료.
//3. M명의 승객 태우는 것이 목표.
//4. 각 칸은 비워있거나 벽이 놓여있다.
//5. 한번에 한명의 승객만 탄다.(여러명 불가능)
//6. 승객은 출발지에서만 탑승, 도착지에서만 하차.
//7. 승객을 고를 때, 가장 가까운 승객 고름.
//7-1. 그런 승객이 여러명이면 행,열이 작은 승객 고름
//8. !!!택시와 승객이 같은 위치에 서있으면 그 승객까지 최단거리는 0이다.!!!
//9. 연료는 한칸 이동시 1만큼 소모됨.
//10. !!한 승객을 목적지에 이동시키면, 소모한 연료양의 두배가 충전됨!!
//11. 이동하는 도중에 연료 바닥나면 실패. 업무 종료.
//11-1 승객을 목적지에 이동시킨 동시에 연료가 바닥나는 경우는 실패가 아님.
//12. 연료는 무한히 담을 수 있음.
//13. 모든 출발지는 서로 다름. 각 손님의 출발지와 목적지는 다르다. 

//문제 풀이 생각
//1. bfs로 택시에서 승객까지 탐색. 거리가 같으면 행열로 비교.
//2. 승객 골라지면 bfs로 출발지에서 목적지까지 거리산출
//2-1 이거로 연료 계산, 주행 후 연료 충전까지.

//변수설정
struct Node {
	int sx, sy, ex, ey;
};
struct SubNode {
	int x, y, dis;
};
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int graph[21][21];
int dis[21][21];
int n,m,taxiX, taxiY, fuel, total;
Node human[401];
bool visited[401];

void dis_init() {
	for (int i = 0; i < n; i++) {
		fill_n(dis[i], n, INF);
	}
}


//void show() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("(%d %d) ",graph[i][j].first, graph[i][j].second);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

bool check(int nx, int ny) {
	return 0 <= nx && nx <= n-1 && 0 <= ny && ny <= n-1;
}
pair<int,int> find_human() {
	//각 칸의 최단거리 구하기
	dis_init();
	queue<pair<int, int>> q;
	q.push({ taxiX,taxiY });
	dis[taxiX][taxiY] = 0;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny) && graph[nx][ny] == 0 && dis[nx][ny] > dis[x][y] + 1) {
				dis[nx][ny] = dis[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	//가장 거리가 짧고, 행렬이 작은 손님 찾기
	int tx = 0, ty = 0;
	int index =0;
	int tdis = 10000000;
	for (int i = 0; i < m; i++) {
		int x = human[i].sx, y = human[i].sy;
		if (!visited[i]) {
			if (dis[x][y] < tdis) {
				tx = x, ty = y;
				index = i;
				tdis = dis[x][y];
			}
			else if (dis[x][y] == tdis && x * n + y < tx * n + ty) {
				tx = x, ty = y;
				index = i;
				tdis = dis[x][y];
			}
		}
	}
	return { index,tdis };
}
int fuel_calc(int target_num) {
	dis_init();
	queue<pair<int, int>> q;
	q.push({ taxiX,taxiY });
	dis[taxiX][taxiY] = 0;
	int ex = human[target_num].ex, ey = human[target_num].ey;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny) && graph[nx][ny] == 0 && dis[nx][ny] > dis[x][y] + 1) {
				dis[nx][ny] = dis[x][y] + 1;
				q.push({ nx,ny });
				if (nx == ex && ny == ey) {
					return dis[nx][ny];
				}
			}
		}
	}
	return dis[ex][ey];
}

int solution() {
	while (true) {


	//1. bfs로 택시에서 승객까지 탐색. 거리가 같으면 행열로 비교.
	pair<int,int> node = find_human();
	//printf("index%d dis%d sx%d sy%d ex%d ey%d\n", node.first, node.second, human[node.first].sx,human[node.first].sy, human[node.first].ex, human[node.first].ey);
	//만약 INF면 손님이 벽으로 갇혀있다는 뜻.
	if (node.second == INF) 
		return -1;
	//승객까지 가는 연료 계산.
	if (node.second >= fuel)
		return -1;
	else
		//택시 위치를 승객 출발지로 업데이트
		taxiX = human[node.first].sx, taxiY =human[node.first].sy;
		fuel -= node.second;
	
	//2. 승객 골라지면 bfs로 출발지에서 목적지까지 거리산출
	int needed = fuel_calc(node.first);
	//printf("%d %d\n",needed, fuel);
	//만약 INF면 목적지가 벽으로 갇혀있다는 뜻.
	if (needed == INF || fuel<needed)
		return -1;
	else {
		//2-1 이거로 연료 계산, 주행 후 연료 충전까지.
		//택시 위치 목적지로 업데이트,손님 업데이트
		visited[node.first] = true;
		taxiX = human[node.first].ex, taxiY = human[node.first].ey;
		fuel -= needed;
		fuel += needed * 2;
		total += 1;
	}

	if (total == m )
		return fuel;
	}
}


int main() {
	scanf("%d %d %d", &n, &m, &fuel);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	scanf("%d %d", &taxiX,&taxiY);
	taxiX--, taxiY--;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &human[i].sx, &human[i].sy, &human[i].ex, &human[i].ey);
		human[i].sx--, human[i].sy--, human[i].ex--, human[i].ey--;
	}

	printf("%d", solution());
	return 0;
}