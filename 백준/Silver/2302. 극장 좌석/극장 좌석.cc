#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[41];
int ans = 1;
int tmp = 1;
int dp[41];

int f(int n) {
	if (n == 0) return 0;
	if (dp[n] != -1) return dp[n];

	dp[n] = f(n - 1) + f(n - 2);

	return dp[n];
 }

int main() {
	cin >> N >> M;
	arr[0] = 1;

	fill(dp, dp + 41, -1);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = arr[i - 1] + 1; j < arr[i]; j++) {
			tmp++;
		}
		tmp = f(tmp);
		if (tmp != 0) ans *= tmp;
		tmp = 0;
	}

	for (int i = arr[M]; i < N; i++) tmp++;
	tmp = f(tmp);
	if (tmp != 0) ans *= tmp;

	cout << ans << "\n";

	return 0;
}