#include <bits/stdc++.h>

using namespace std;

int N, M;
int m[1001][1001];
int dp[1001][1001];

int main() {
	cin >> N >> M;
	fill(&dp[0][0], &dp[1000][1001], 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp;
			tmp = max({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] });
			dp[i][j] = tmp + m[i][j];
		}
	}

	cout << dp[N][M] << "\n";

	return 0;
}