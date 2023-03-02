#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int ans = 1; // 정답
	int ans_tmp = 1; //정답 임시
	char tmp; // tnp
	int n;
	cin >> n;

	char** board = new char* [n]; // 빨C 파P 초Z 노Y
	char** board_tmp = new char* [n]; //임시 배열

	for (int i = 0; i < n; i++) { // 2차원배열 동적할당
		board[i] = new char[n];
	}

	for (int i = 0; i < n; i++) { // 2차원배열 동적할당
		board_tmp[i] = new char[n];
	}

	for (int x = 0; x < n; x++) { // C P Z Y 입력
		for (int y = 0; y < n; y++) {
			cin >> board[x][y];
		}
	}



	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {

			for (int x = 0; x < n; x++) { // 배열 복사
				for (int y = 0; y < n; y++) {
					board_tmp[x][y] = board[x][y];
				}
			}
			if (a == b) {
				for (int p = 0; p < n - 1; p++) { // 세로확인
					if (board_tmp[p][b] == board_tmp[p + 1][b]) {
						ans_tmp++;
						ans = max(ans, ans_tmp);
					}
					else {
						ans_tmp = 1;
					}
				}
				ans_tmp = 1;

				for (int q = 0; q < n - 1; q++) { // 가로확인
					if (board_tmp[a][q] == board_tmp[a][q + 1]) {
						ans_tmp++;
						ans = max(ans, ans_tmp);
					}
					else {
						ans_tmp = 1;
					}
				}
				ans_tmp = 1;
			}

			//세로 바꿈----------------
			if (a == n - 1 || board_tmp[a][b] == board_tmp[a+1][b]) {

			}
			else {
				tmp = board_tmp[a][b];
				board_tmp[a][b] = board_tmp[a + 1][b];
				board_tmp[a + 1][b] = tmp; // 아래랑 바꿈
			}
			for (int p = 0; p < n - 1; p++) { // 세로확인
				if (board_tmp[p][b] == board_tmp[p + 1][b]) {
					ans_tmp++;
					ans = max(ans, ans_tmp);
				}
				else {
					ans_tmp = 1;
				}
			}
			ans_tmp = 1;

			for (int q = 0; q < n - 1; q++) { // 가로확인
				if (board_tmp[a][q] == board_tmp[a][q + 1]) {
					ans_tmp++;
					ans = max(ans, ans_tmp);
				}
				else {
					ans_tmp = 1;
				}
			}
			ans_tmp = 1;

			if (a != n - 1) { //세로 마지막줄엔 (세+1)안함!
				for (int q = 0; q < n - 1; q++) { // (세+1)가로확인
					if (board_tmp[a + 1][q] == board_tmp[a + 1][q + 1]) {
						ans_tmp++;
						ans = max(ans, ans_tmp);
					}
					else {
						ans_tmp = 1;
					}
				}
				ans_tmp = 1;
			}
			if (a == n - 1) {

			}
			else {
				tmp = board_tmp[a][b];
				board_tmp[a][b] = board_tmp[a + 1][b];
				board_tmp[a + 1][b] = tmp; //원래대로
			}
			//세로 바꿈----------------

			//가로 바꿈----------------
			if (b == n - 1 || board_tmp[a][b] == board_tmp[a][b+1]) {

			}
			else {
				tmp = board_tmp[a][b];
				board_tmp[a][b] = board_tmp[a][b + 1];
				board_tmp[a][b + 1] = tmp; // 오른쪽이랑 바꿈
	
			}
			for (int p = 0; p < n - 1; p++) { // 세로확인
				if (board_tmp[p][b] == board_tmp[p + 1][b]) {
					ans_tmp++;
					ans = max(ans, ans_tmp);
				}
				else {
					ans_tmp = 1;
				}
			}
			ans_tmp = 1;

			for (int q = 0; q < n - 1; q++) { // 가로확인
				if (board_tmp[a][q] == board_tmp[a][q + 1]) {
					ans_tmp++;
					ans = max(ans, ans_tmp);
				}
				else {
					ans_tmp = 1;
				}
			}
			ans_tmp = 1;

			if (b != n - 1) { //가로 마지막줄엔 (가+1)안함!
				for (int q = 0; q < n - 1; q++) { // (가+1)세로확인
					if (board_tmp[q][b + 1] == board_tmp[q + 1][b + 1]) {
						ans_tmp++;
						ans = max(ans, ans_tmp);
					}
					else {
						ans_tmp = 1;
					}
				}
				ans_tmp = 1;
			}
			if (b == n - 1) {

			}
			else {
				tmp = board_tmp[a][b];
				board_tmp[a][b] = board_tmp[a][b+1];
				board_tmp[a][b+1] = tmp; //원래대로
			}
			//가로 바꿈----------------
		}
	}

	cout << ans;





	for (int z = 0; z < n; z++) { // 2차원 배열 delete
		delete[] board[z];
	}
	delete[] board;
	for (int z = 0; z < n; z++) { // 2차원 배열 delete
		delete[] board_tmp[z];
	}
	delete[] board_tmp;

	return 0;
}