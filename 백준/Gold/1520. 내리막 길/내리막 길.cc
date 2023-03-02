#include <bits/stdc++.h>

using namespace std;

int N, M;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int dp[501][501];
int m[501][501];
int ans = 0;

int dfs(int y, int x) {

	if (y == N - 1 && x == M - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		
		if (m[ny][nx] < m[y][x]) {
			dp[y][x] = dp[y][x] + dfs(ny, nx);
		}
	}
	return dp[y][x];
}

int main() {
	cin >> N >> M;
	fill(&dp[0][0], &dp[500][501], -1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}

	cout << dfs(0, 0) << "\n";

	return 0;
}