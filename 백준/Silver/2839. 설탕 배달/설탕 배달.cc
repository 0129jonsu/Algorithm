#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[5001];
bool im = true;

int f(int n) {
	if (n == 0) {
		im = false;
		return 0;
	}
	if (dp[n] != -1) return dp[n];
	dp[n] = n;

	if (n - 5 >= 0) dp[n] = min(dp[n], f(n - 5) + 1);
	if (n - 3 >= 0) dp[n] = min(dp[n], f(n - 3) + 1);

	return dp[n];
}

int main() {
	fill(dp, dp + 5001, -1);
	cin >> N;

	int ans = f(N);

	if (im) cout << "-1" << "\n";
	else cout << ans << "\n";

	return 0;
}