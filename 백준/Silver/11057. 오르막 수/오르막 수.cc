#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long a;
long long dp[1001][10];

long long f(long long n ,long long k) {
	if (n == 1) return 1;
	if (dp[n][k] != -1) return dp[n][k];

	long long ans = 0;

	for (int i = 0; i <= k; i++) {
		ans = (ans + f(n - 1, i)) % 10007;
		dp[n][k] = ans;
	}
	return ans;

}

int main() {
	fill(&dp[0][0], &dp[1000][10], -1);
	cin >> N;
	
	for (int i = 0; i < 10; i++) {
		a = (a + f(N, i)) % 10007;
	}

	cout << a;

	return 0;
}