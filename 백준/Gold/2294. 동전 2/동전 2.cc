#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int coin[100001];
int dp[101][100001];
int xx = 1000000000;

int f(int n, int k) {
	if (n == N) {
		if (k == 0) return 0;
		else return xx;
	}

	if (dp[n][k] != -1) return dp[n][k];

	int ans = f(n + 1, k);
	if (k >= coin[n]) ans = min(ans, f(n, k - coin[n]) + 1);

	dp[n][k] = ans;

	return ans;
}

int main() {
	cin >> N >> K;
	
	fill(&dp[0][0], &dp[100][100001], -1);

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	int ans = f(0, K);

	if (ans == xx) {
		cout <<  "-1";
		return 0;
	}
	cout << ans;

	return 0;
}