#include <iostream>

using namespace std;

int n;
int t[501][501];
int dp[501][501];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int tmp;
			cin >> tmp;
			t[i][j] = tmp;
		}
	}
	dp[1][1] = t[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + t[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + t[i + 1][j + 1]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;

	return 0;
}