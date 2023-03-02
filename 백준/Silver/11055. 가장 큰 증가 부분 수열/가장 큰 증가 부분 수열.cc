#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long ans = 0;
long long arr[1001];
long long dp[1001];


int main() {
	fill(dp, dp + 1001, -1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}