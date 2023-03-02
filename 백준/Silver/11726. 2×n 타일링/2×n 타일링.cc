#include <iostream>
#include <algorithm>

using namespace std;

long long dp[1001];
long long N;

long long f(long long n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (dp[n] != -1) return dp[n];

	dp[n] = (f(n - 1) + f(n - 2)) % 10007;

	return dp[n];

}

int main() {
	cin >> N;
	fill(dp, dp + 1001, -1);

	cout << f(N);

	return 0;
}