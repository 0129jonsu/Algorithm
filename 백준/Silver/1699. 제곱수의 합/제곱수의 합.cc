#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int dp[100001];

int f(int n, int k) {
	if (n == 0) return 0;
	else if (int(pow(k, 2)) > N) return 1000000000;
	if (dp[n] != -1) return dp[n];

	int ans = f(n, k + 1);

	if (n >= int(pow(k, 2))) ans = min(ans, f(n - int(pow(k, 2)), k) + 1);

	dp[n] = ans;
	return ans;

}

int main() {
	cin >> N;
	fill(dp, dp + 100001, -1);

	cout << f(N, 1);

	return 0;
}