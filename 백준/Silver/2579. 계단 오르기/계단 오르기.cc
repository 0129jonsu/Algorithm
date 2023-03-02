#include <bits/stdc++.h>

using namespace std;

int N;
int dp[301];
int arr[301];

int f(int n) {
	if (n < 0) return 0;
	if (dp[n] != -1) return dp[n];
	
	dp[n] = max(dp[n], f(n - 2) + arr[n]);
	dp[n] = max(dp[n], f(n - 3) + arr[n - 1] + arr[n]);

	return dp[n];
}


int main() {
	cin >> N;
	fill(dp, dp + 300, -1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << f(N - 1) << "\n";

	return 0;
}