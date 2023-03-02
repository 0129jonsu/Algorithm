#include <bits/stdc++.h>

using namespace std;

int N;
int m[101][101];
long long dp[101][101];

long long dfs(int y, int x) {
	if (y == N - 1 && x == N - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	if (dp[y][x] == -1) {
		dp[y][x] = 0;

		int ny = y + m[y][x];
		int nx = x + m[y][x];

		if (ny < N) dp[y][x] += dfs(ny, x);
		if (nx < N) dp[y][x] += dfs(y, nx);
	}
	return dp[y][x];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}

	fill(&dp[0][0], &dp[100][101], -1);

	cout << dfs(0, 0) << "\n";

	return 0;
}