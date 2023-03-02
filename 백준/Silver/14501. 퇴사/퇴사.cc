#include <iostream>

using namespace std;

int N;
int ans = 0;
int dp[22] = { 0, };
pair<int,int> arr[22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;
		arr[i] = { T,P };
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i],dp[i - 1]);
		dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
	}

	for (int i = 1; i <= N+1; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}