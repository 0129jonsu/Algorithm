#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	long long dp[101];


	for (int i = 0; i < N; i++) {
		fill(dp, dp + 100, 0);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		int tmp;
		cin >> tmp;
			for (int j = 3; j <= tmp; j++) {
				dp[j] = dp[j - 2] + dp[j - 3];
			}
		cout << dp[tmp] << "\n";
	}

	return 0;
}