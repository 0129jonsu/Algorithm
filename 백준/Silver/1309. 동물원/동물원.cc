#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main() {
	int N;
	cin >> N;

	dp[0] = 3;
	dp[1] = 7;

	for (int i = 2; i < N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1] * 2) % 9901;
	}

	cout << dp[N - 1];

	return 0;
}