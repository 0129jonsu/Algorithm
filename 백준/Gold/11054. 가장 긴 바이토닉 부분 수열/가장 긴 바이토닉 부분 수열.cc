#include <iostream>

using namespace std;

int N;
int A[1001];
int dp[1001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	fill(&dp[0][0], &dp[1000][2], 1);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A[i] = tmp;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
		}
	}

	 for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= i; j--) {
			if (A[i] > A[j]) dp[i][1] = max(dp[i][1], dp[j][1] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		dp[i][0] = dp[i][0] + dp[i][1];
		ans = max(ans, dp[i][0]);
	}

	cout << ans - 1;

	return 0;
}