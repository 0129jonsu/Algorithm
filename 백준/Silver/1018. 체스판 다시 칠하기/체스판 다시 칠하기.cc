#include <iostream>
#include <algorithm>

using namespace std;

	

int main() {
	char board[50][50];

	int m, n; // 세 가
	int count = 32;

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i <= m - 8; i++) {
		for (int j = 0; j <= n - 8; j++) {
			int tmp = 0;

			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if ((x + y) % 2 == 0) {
						if (board[x + i][y + j] == 'W');
						else tmp++;

					}
					else {
						if (board[x + i][y + j] == 'W') tmp++;
					}
				}
			}
			count = min(tmp, count);
			tmp = 0;

			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if ((x + y) % 2 == 0) {
						if (board[x + i][y + j] == 'B');
						else tmp++;
					}
					else {
						if (board[x + i][y + j] == 'B') tmp++;
					}
				}
			}
			count = min(tmp, count);
			tmp = 0;
		}
	}
	cout << count;
	
 	return 0;
}