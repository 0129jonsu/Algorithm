#include <iostream>
#include <algorithm>

using namespace std;

long long N, K;
long long dp[1001][1001];

long long f(long long n, long long k) {
	if (n == k || k == 0) return 1;
	if (dp[n][k] != -1) return dp[n][k];

	dp[n][k] = (f(n - 1, k) + f(n - 1, k - 1)) % 10007;

	return dp[n][k];
}

int main() {
	fill(&dp[0][0], &dp[1000][1001], -1);
	cin >> N >> K;

	cout << f(N, K);

	return 0;
}