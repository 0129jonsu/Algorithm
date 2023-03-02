#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int dp[1001];
	int arr[1001];
	int ans = 0;
	cin >> N;

	fill(dp, dp + 1001, 1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j >= 0; j--) {
			if (arr[j] > arr[i] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
			ans = max(ans, dp[i]);
		}
	}

	cout << ans << "\n";

	return 0;
}