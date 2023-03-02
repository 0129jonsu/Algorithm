#include <bits/stdc++.h>

using namespace std;

int N;
int dp[50001];

int main() {
	cin >> N;
	fill(dp, dp + 500, -1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++) {
		int m = 50001;
		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			m = min(m, dp[tmp]);
		}
		dp[i] = m + 1;
	}

	cout << dp[N];
	return 0;
}