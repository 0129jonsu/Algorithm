#include <iostream> 
#include <algorithm>

using namespace std;

int dp[11];

int f(int n) {
	if (n < 0) return 0;
	if (dp[n] != -1) return dp[n];

	dp[n] = f(n - 3) + f(n - 2) + f(n - 1);

	return dp[n];

}

int main() {
	int T;

	cin >> T;
	fill(dp, dp + 11, -1);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 0; i < T; i++) {
		int tmp;
		cin >> tmp;
		cout << f(tmp) << "\n";
	}

	return 0;
}