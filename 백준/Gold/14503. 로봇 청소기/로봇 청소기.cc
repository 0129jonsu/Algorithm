#include <iostream>

using namespace std;

int N, M, r, c, d; ;
int map[51][51];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int t = 0;
int cnt = 0;

void f(int x, int y) {
	if (map[y][x] == 0) {
		map[y][x] = 2;
		cnt++;
	}
	if (map[y + 1][x] == 0 || map[y][x + 1] == 0 || map[y - 1][x] == 0 || map[y][x - 1] == 0) {
		do {
			t -= 1;
			if (t == -1) t += 4;
		} while (map[y + dy[t]][x + dx[t]] != 0);
		f(x + dx[t], y + dy[t]);
	}
	else {
		if (map[y - dy[t]][x - dx[t]] == 1) return;
		f(x - dx[t], y - dy[t]);
	}
}


int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	t = d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	f(c, r);

	cout << cnt;

	return 0;
}