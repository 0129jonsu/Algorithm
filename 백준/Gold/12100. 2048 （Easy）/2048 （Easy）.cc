#include <iostream>

using namespace std;

int N;
int map[21][21];
int map_tmp[21][21];
int d[6];
int ans = 0;
void up() {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map_tmp[i - 1][j] == 0) {
				int idx = i - 1;
				while (map_tmp[idx][j] == 0 && idx != 0)idx--;
				idx++;
				if (idx == 1) {
					if (map_tmp[0][j] == 0) idx = 0;
				}
				map_tmp[idx][j] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map_tmp[i - 1][j] == map_tmp[i][j]) {
				map_tmp[i - 1][j] *= 2;
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map_tmp[i - 1][j] == 0) {
				int idx = i - 1;
				while (map_tmp[idx][j] == 0 && idx != 0)idx--;
				idx++;
				if (idx == 1) {
					if (map_tmp[0][j] == 0) idx = 0;
				}
				map_tmp[idx][j] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}
		}
	}

}
void right() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (map_tmp[i][j + 1] == 0) {
				int idx = j + 1;
				while (map_tmp[i][idx] == 0 &&idx != N-1)idx++;
				idx--;
				if (idx == N - 2) {
					if (map_tmp[i][N - 1] == 0) idx = N - 1;
				}
				map_tmp[i][idx] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N ; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (map_tmp[i][j + 1] == map_tmp[i][j]) {
				map_tmp[i][j + 1] *= 2;
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (map_tmp[i][j + 1] == 0) {
				int idx = j + 1;
				while (map_tmp[i][idx] == 0 && idx != N-1)idx++;
				idx--;
				if (idx == N - 2) {
					if (map_tmp[i][N - 1] == 0) idx = N - 1;
				}
				map_tmp[i][idx] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}  
		}
	}
}
void down() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map_tmp[i + 1][j] == 0) {  
				int idx = i + 1;
				while (map_tmp[idx][j] == 0 && idx != N-1) idx++;
				idx--;
				if (idx == N - 2) {
					if (map_tmp[N - 1][j] == 0) idx = N - 1;
				}
				map_tmp[idx][j] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map_tmp[i + 1][j] == map_tmp[i][j]) {
				map_tmp[i + 1][j] *= 2;
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (map_tmp[i + 1][j] == 0) {
				int idx = i + 1;
				while (map_tmp[idx][j] == 0 && idx != N - 1) idx++;
				idx--;
				if (idx == N-2) {
					if (map_tmp[N-1][j] == 0) idx = N-1;
				}
				map_tmp[idx][j] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}
		}
	}
}
void left() {
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map_tmp[i][j - 1] == 0) {
				int idx = j - 1;
				while (map_tmp[i][idx] == 0 && idx != 0) idx--;
				idx++;
				if (idx == 1) {
					if (map_tmp[i][0] == 0) idx = 0;
				}
				map_tmp[i][idx] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map_tmp[i][j - 1] == map_tmp[i][j]) {
				map_tmp[i][j - 1] *= 2;
				map_tmp[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map_tmp[i][j - 1] == 0) {
				int idx = j - 1;
				while (map_tmp[i][idx] == 0 && idx != 0) idx--;
				idx++;
				if (idx == 1) {
					if (map_tmp[i][0] == 0) idx = 0;
				}
				map_tmp[i][idx] = map_tmp[i][j];
				map_tmp[i][j] = 0;
			}
		}
	}
}

void cal_max() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, map_tmp[i][j]);
		}
	}
}

void play() {
	for (int i = 0; i < 5; i++) {
		if (d[i] == 0) right();
		else if (d[i] == 1) up();
		else if (d[i] == 2) left();
		else if (d[i] == 3) down();
	}
	cal_max();
}

void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map_tmp[i][j] = map[i][j];
		}
	}
}

void sel_dir(int cnt, int idx) {
	if (cnt == 5) {
		copy();
		play();
		return;
	}

	for (int i = 0; i < 4; i++) {
		d[cnt] = i;
		sel_dir(cnt + 1, i);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	sel_dir(0, 0);

	cout << ans;

	return 0;
}