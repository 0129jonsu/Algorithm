#include <bits/stdc++.h>

using namespace std;

int T, N, M;
int dp[31][31];

int f(int m, int n) {
	if (n == 0 || n == m) return 1;
	if (dp[m][n] != -1) return dp[m][n];

	dp[m][n] = f(m - 1, n) + f(m - 1, n - 1);

	return dp[m][n];
}

int main() {
	fill(&dp[0][0], &dp[30][31], -1);
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << f(M, N) << "\n";
	}

	return 0;
}