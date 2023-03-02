#include <bits/stdc++.h>

using namespace std;

int N;
int arr[10001];
int dp[10001];

int main() {
	fill(dp, dp + 10001, 0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = dp[0] + arr[1];
	for (int i = 2; i < N; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[N - 1] << "\n";

	return 0;
}