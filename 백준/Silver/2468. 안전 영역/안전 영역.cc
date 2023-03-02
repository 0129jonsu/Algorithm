#include <bits/stdc++.h>

using namespace std;

int N;
int m[101][101] = { 0, };
bool visited[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cnt = 0;
int hm = 0;

void dfs(int y, int x, int h) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (m[ny][nx] > h && !visited[ny][nx]) dfs(ny, nx, h);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			hm = max(hm, m[i][j]);
		}
	}

	int ans = 0;
	for (int h = 0; h <= hm; h++) {
		fill(&visited[0][0], &visited[100][101], false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (m[i][j] > h && !visited[i][j]) {
					dfs(i, j, h);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
		cnt = 0;
	}

	cout << ans;

	return 0;
}