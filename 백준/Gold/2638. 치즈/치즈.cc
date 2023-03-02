#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M;
int map[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int ans = 0;

void f() {
	memset(visited, false, sizeof(visited));
	ans++;
	q.push({ 0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx]) continue;
			if (map[ny][nx] == 0) {
				q.push({ nx,ny });
				visited[ny][nx] = true;
			}
			else map[ny][nx]++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] >= 3) map[i][j] = 0;
			else if (map[i][j] == 2) map[i][j] = 1;
		}
	}
}

bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) return 1;
		}
	}
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	while (check()) f();

	cout << ans;

	return 0;
}