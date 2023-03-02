#include <bits/stdc++.h>

using namespace std;

int arr[1001][3];
int dp[1001][3];

int N;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			if (i == 0) dp[i][j] = arr[i][j];
		}
	}

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	cout << min({ dp[N - 1][0],dp[N - 1][1],dp[N - 1][2] }) << "\n";

	return 0;
}