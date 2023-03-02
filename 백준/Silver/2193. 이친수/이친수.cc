#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long dp[91];

long long pn(long n) {
	if (n == 1 || n == 2) return 1;
	if (dp[n] != -1) return dp[n];

	dp[n] = pn(n - 1) + pn(n - 2);

	return dp[n];
}

int main() {
	cin  >> N;
	fill(dp, dp + 91, -1);

	cout << pn(N);
	return 0;
}