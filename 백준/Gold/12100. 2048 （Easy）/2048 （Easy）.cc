#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

int n, answer;
int graph[21][21];
bool visited[21][21];

void init() {
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], n, false);
	}
}

void show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void turn(int graph[21][21]) {
	int tmp_graph[21][21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_graph[j][n-1-i] = graph[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = tmp_graph[i][j];
		}
	}

}

void dfs(int depth, int graph[21][21]) {
	if (depth == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				answer = max(answer, graph[i][j]);
			}
		}
		return;
	}

	//그래프 돌리기
	for (int dir = 0; dir < 4; dir++) {
		turn(graph);

		init();
		int tmp_graph[21][21];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp_graph[i][j] = graph[i][j];
			}
		}

		//위로 쭉 올리기
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int k = i - 1;
				for (; k >= 0 && tmp_graph[k][j] == 0; k--) {
				}
				if (!visited[k][j] && tmp_graph[k][j] == tmp_graph[i][j]) {
					visited[k][j] = true;
					tmp_graph[k][j] *= 2;
					tmp_graph[i][j] = 0;
				}
				else {
					int tmp = tmp_graph[i][j];
					tmp_graph[i][j] = 0;
					tmp_graph[k + 1][j] = tmp;

				}
			}
		}
		dfs(depth + 1, tmp_graph);

	}


}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	dfs(0, graph);
	printf("%d", answer);
	return 0;
}