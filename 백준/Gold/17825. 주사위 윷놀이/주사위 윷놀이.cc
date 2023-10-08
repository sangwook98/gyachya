#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int answer;
int arr[35];
int turn[35];
int score[35];
bool check[35];
int horse[4];
int dice[10];


//void show() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//
//bool check(int nx, int ny) {
//	return 0 <= nx && nx <= n - 1 && 0 <= ny && ny <= m - 1;
//}



void dfs(int index, int total) {
	//if(total >= 210)
	//	shh(index,total);

	if (index == 10) {
		answer = max(answer, total);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int prev = horse[i];
		int now = prev;
		int move = dice[index];

		if (turn[now]) {
			now = turn[now];
			move--;
		}
		while (move--) {
			now = arr[now];
		}

		if (now != 21 && check[now])
			continue;

		horse[i] = now;
		check[prev] = false;
		check[now] = true;


		dfs(index + 1, total + score[now]);

		horse[i] = prev;
		check[prev] = true;
		check[now] = false;
	}
	
	
}

int main() {
	for (int i = 0; i < 10; i++)
		scanf("%d", &dice[i]);

	//주사위 맵 만들기
	for (int i = 0; i < 21;i++) {
		arr[i] = i + 1;
	}
	arr[21] = 21;

	for (int i = 22; i < 28; i++) {
		arr[i] = i + 1;
	}

	arr[28] = 29, arr[29] = 30, arr[30] = 25;
	arr[31] = 32, arr[32] = 25, arr[27] = 20;

	turn[5] = 22, turn[10] = 31; turn[15] = 28;
	turn[25] = 26;

	for (int i = 0; i < 21; i++) {
		score[i] = i * 2;
	}
	score[22] = 13, score[23] = 16, score[24] = 19;
	score[25] = 25, score[26] = 30, score[27] = 35;
	score[28] = 28, score[29] = 27, score[30] = 26;
	score[31] = 22, score[32] = 24;



	dfs(0,0);

	printf("%d", answer);
	return 0;
}