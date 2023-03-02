#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000001];

int f(int n) {
	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	int res = f(n - 1) + 1;
	if (n % 3 == 0) res = min(res, f(n / 3) + 1);
	if (n % 2 == 0) res = min(res, f(n / 2) + 1);
	dp[n] = res;
	return res;
}

int main() {
	int N;
	cin >> N;
	fill(dp, dp + 1000001, -1);

	cout << f(N);


	return 0;
}