#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int n, t, x, y, answer;
bool check[2][4][6];

void show(int index) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", check[index][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void setting1(int index,int t,int x,int y) {
	int x1, y1,x2,y2;

	if (t != 3) {
		int now = 1;
		for (int j = 2; j < 6; j++) {
			if (!check[index][x][j]) {
				now = j;
			}
			else {
				break;
			}
		}

		x1 = x, y1 = now;
		if (t == 1) {
			x2 = x, y2 = now;
		}
		else if (t == 2) {
			x2 = x, y2 = now - 1;
		}
	}
	else {
		int now1 = 1;
		int now2 = 1;
		for (int j = 2; j < 6; j++) {
			if (!check[index][x][j]) {
				now1 = j;
			}
			else {
				break;
			}
		}
		for (int j = 2; j < 6; j++) {
			if (!check[index][x+1][j]) {
				now2 = j;
			}
			else {
				break;
			}
		}
		int now = min(now1, now2);
		x1 = x, y1 = now;
		x2 = x + 1, y2 = now;
	}
	check[index][x1][y1] = true;
	check[index][x2][y2] = true;
}

void setting2(int index, int t, int x, int y) {
	int x1, y1, x2, y2;

	if (t != 2) {
		int now = 1;
		for (int j = 2; j < 6; j++) {
			if (!check[index][x][j]) {
				now = j;
			}
			else {
				break;
			}
		}

		x1 = x, y1 = now;
		if (t == 1) {
			x2 = x, y2 = now;
		}
		else if (t == 3) {
			x2 = x, y2 = now - 1;
		}
	}
	else {
		int now1 = 1;
		int now2 = 1;
		for (int j = 2; j < 6; j++) {
			if (!check[index][x][j]) {
				now1 = j;
			}
			else {
				break;
			}
		}
		for (int j = 2; j < 6; j++) {
			if (!check[index][x - 1][j]) {
				now2 = j;
			}
			else {
				break;
			}
		}
		int now = min(now1, now2);
		x1 = x, y1 = now;
		x2 = x - 1, y2 = now;
	}
	check[index][x1][y1] = true;
	check[index][x2][y2] = true;
}

void move(int index,int start, int dis) {
	for (int i = 0; i < 4; i++) {
		check[index][i][start + dis] = check[index][i][start];
		check[index][i][start] = false;
	}
}

void tettris(int index) {
	int stk[6] = { 0,0,0,0,0,0 };
	int tmp = 0;
	for (int j = 5; j > 1; j--) {
		stk[j] = tmp;
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (check[index][i][j])
				cnt++;
		}
		if (cnt == 4) {
			tmp++;
			answer++;
		}
	}
	stk[1] = tmp, stk[0] = tmp;
	
	for (int j = 4; j >= 0; j--) {
		if(stk[j])
			move(index,j, stk[j]);
	}
}



void imgye(int index) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (check[index][i][0]) {
			cnt++;
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (check[index][i][1]) {
			cnt++;
			break;
		}
	}

	if (cnt == 1) {
		for (int j = 4; j >= 0; j--) {
			move(index,j, 1);
		}
	}
	else if (cnt == 2) {
		for (int j = 3; j >= 0; j--) {
			move(index,j, 2);
		}
	}

}

int main() {
	scanf("%d", &n);
	int nn = n;
	while (n--) {
		scanf("%d %d %d", &t, &x, &y);

		setting1(0,t, x, y);
		tettris(0);
		imgye(0);
		//show(0);
		//printf("------------\n");

		setting2(1, t, 3-y, x);
		tettris(1);
		imgye(1);
		//show(1);
		//printf("%d----end----\n",nn-n);
	}

	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 2; k < 6; k++) {
				if (check[i][j][k])
					cnt++;
			}
		}
	}
	printf("%d\n%d", answer,cnt);
	return 0;
}