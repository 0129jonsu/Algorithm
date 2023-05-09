#include <iostream>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

int N, M;
tuple<int, int, int> s;
queue<tuple<int, int, int>> q;
char map[501][501];
int visited[501][501][6];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int roll(int n, int p) {
	if (p == 0) {
		if (n == 0) return 2;
		else if (n == 1) return 4;
		else if (n == 2) return 3;
		else if (n == 3) return 1;
	}
	if (p == 1) {
		if (n == 0) return 1;
		else if (n == 1) return 0;
		else if (n == 2) return 1;
		else if (n == 3) return 5;
	}
	if (p == 2) {
		if (n == 0) return 5;
		else if (n == 1) return 2;
		else if (n == 2) return 0;
		else if (n == 3) return 2;
	}
	if (p == 3) {
		if (n == 0) return 0;
		else if (n == 1) return 3;
		else if (n == 2) return 5;
		else if (n == 3) return 3;
	}
	if (p == 4) {
		if (n == 0) return 4;
		else if (n == 1) return 5;
		else if (n == 2) return 4;
		else if (n == 3) return 0;
	}
	if (p == 5) {
		if (n == 0) return 3;
		else if (n == 1) return 1;
		else if (n == 2) return 2;
		else if (n == 3) return 4;
	}
	return 0;
}

void f() {
	while (!q.empty()) {
		int curr_x = get<0>(q.front());
		int curr_y = get<1>(q.front());
		int curr_p = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];
			int next_p = roll(i, curr_p);
			if (map[next_y][next_x] == '#' || next_x >= M || next_x < 0 || next_y >= N || next_y < 0) continue;
			else if (map[next_y][next_x] == 'R') {
				if (next_p != 0) continue;
				else {
					cout << visited[curr_y][curr_x][curr_p] + 1;
					return;
				}
			}

			else if (!visited[next_y][next_x][next_p] && (map[next_y][next_x] == '.' || map[next_y][next_x] == 'D')) {
				q.push({ next_x, next_y, next_p });
				visited[next_y][next_x][next_p] = visited[curr_y][curr_x][curr_p] + 1;
			}
		}
	}
	cout << -1;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') s = make_tuple(j, i, 0);
		}
	}
	q.push(s);

	f();

	return 0;
}