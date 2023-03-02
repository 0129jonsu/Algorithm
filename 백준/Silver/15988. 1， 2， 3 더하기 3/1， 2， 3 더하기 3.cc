#include <iostream> 
#include <algorithm>

using namespace std;

long long dp[1000001];

long long f(long long n) {
	if (n < 0) return 0;
	if (dp[n] != 0) return dp[n];

	dp[n] = (f(n - 1) % 1000000009 + f(n - 2) % 1000000009 + f(n - 3) % 1000000009) % 1000000009;

	return dp[n];

}

int main() {
	int T;

	cin >> T;
	fill(dp, dp + 1000001, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 0; i < T; i++) {
		long long tmp;
		cin >> tmp;
		cout << f(tmp) << "\n";
	}

	return 0;
}