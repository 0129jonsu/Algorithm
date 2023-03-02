#include <iostream>
#include <algorithm>

using namespace std;

int N;
int p[10000];
int dp[10000001];

int f(int n, int k) {
	if (n == 0 || k > N) return 0;
	if (dp[n] != -1) return dp[n];

	int ans = max(ans, f(n - k, k) + p[k]);
	if (n - (k + 1) >= 0) ans = max(ans, f(n, k + 1));

	dp[n] = ans;
	return ans;

}

int main() {
	fill(dp, dp + 10000001, -1);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	cout << f(N, 1);

	return 0;
}