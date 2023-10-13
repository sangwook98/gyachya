#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
// 09:22 start
// 제약사항
// 테스트케이스 50개,6 ≤ N ≤ 20,  2 ≤ X ≤ 4, 1<= 지형높이 <= 6,
// 
// 조건들
//1. 각 셀의 숫자는 그 지형의 높이를 의미한다.
//2. 활주로는 가로를 쭉, 세로로 쭉으로만 설치할 수 있다.
//3. 경사로는 높이 차이가 1이고, 낮은 지형의 높이가 동일하게 경사로의 길이만큼 연속되는 곳만 설치 가능.
//4. 활주로를 건설할 수 있는 경우의 수를 계산하라.

// 엣지케이스
//1. 전체가 높이가 같은 구간
//2. FIG 8-1처럼 높은데가 가운데서 시작.
//3. 높이가 6,5,4 이런것도 해봐야 함.

// 문제 생각
// 테스트 케이스가 많으니 전역변수들 초기화 필요
// 가로 세로 탐색만 제대로 하면됨
// check 가로 함수
// check 세로 함수

//변수들
int t, n, x;
int graph[22][22];
bool visited[22][22];

void visit_init() {
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], n, false);
	}
}

bool garo_check(int i) {
	for (int j = 1; j < n; j++) {
		if (graph[i][j - 1] == graph[i][j]) {
			continue;
		}
		//왼쪽이 한칸 클 경우
		else if (graph[i][j - 1] -1 == graph[i][j]) {
			int level = graph[i][j];
			for (int k = 0; k < x; k++) {
				if ( j+k <=n-1 && level == graph[i][j + k] && !visited[i][j+k]) {
					visited[i][j + k]= true;
				}
				else {
					return false;
				}
			}
		}
		//오른쪽이 한칸 클 경우
		else if (graph[i][j - 1] == graph[i][j] - 1) {
			int level = graph[i][j]-1;
			for (int k = 0; k < x; k++) {
				if ( 0<= j-1-k &&level == graph[i][j-1 - k] && !visited[i][j-1 - k]) {
					visited[i][j-1 -k]= true;
				}
				else {
					return false;
				}
			}

		}
		//두칸 이상 차이날 경우
		else {
			return false;
		}
	}
	return true;
}
bool sero_check(int j) {
	for (int i = 1; i < n; i++) {
		if (graph[i-1][j] == graph[i][j]) {
			continue;
		}
		//위쪽이 한칸 클 경우
		else if (graph[i-1][j] - 1 == graph[i][j]) {
			int level = graph[i][j];
			for (int k = 0; k < x; k++) {
				if (i + k <= n - 1 && level == graph[i+k][j] && !visited[i+k][j]) {
					visited[i+k][j]=true;
				}
				else {
					return false;
				}
			}
		}
		//아래쪽이 한칸 클 경우
		else if (graph[i-1][j] == graph[i][j]-1) {
			int level = graph[i][j] - 1;
			for (int k = 0; k < x; k++) {
				if (0 <= i - 1 - k && level == graph[i-1-k][j] && !visited[i-1-k][j]) {
					visited[i-1-k][j]= true;
				}
				else {
					return false;
				}
			}

		}
		//두칸 이상 차이날 경우
		else {
			return false;
		}
	}
	return true;
}

int solution() {
	//visit 초기화
	//printf("garo\n");
	int answer = 0;
	visit_init();
	for (int i = 0; i < n; i++) {
		if (garo_check(i)) {
			//printf("%d\n", i);
			answer++;
		}
	}
	//printf("sero\n");
	visit_init();
	for (int j = 0; j < n; j++) {
		if (sero_check(j)) {
			//printf("%d\n", j);
			answer++;
		}
	}
	return answer;
}

int main() {

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d", &n, &x);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &graph[j][k]);
			}
		}

		int answer = 0;
		answer = solution();

		printf("#%d %d\n", i, answer);


	}
	return 0;
};