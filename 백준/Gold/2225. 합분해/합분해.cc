#include <iostream>

using namespace std;

int N, K;
long long arr[201];
long long dp[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}
	
	for (int k = 2; k <= K; k++) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				dp[k][i] = (dp[k][i] + dp[k - 1][j]) % 1000000000;
			}
		}
	}

	cout << dp[K][N];

	return 0;
}