#include <iostream>
#include <algorithm>

using namespace std;

int v[2][100001], dp[100001][3];

int N;

int f(int p, int q) {
	if (p == N) return 0;
	if (dp[p][q] != -1) return dp[p][q];

	int ans = f(p + 1, 0);

	if (q != 1) ans = max(ans, f(p + 1, 1) + v[0][p]);
	if (q != 2) ans = max(ans, f(p + 1, 2) + v[1][p]);

	dp[p][q] = ans;
	return ans;
}

int main() {
	int T;
	cin >> T;

	for (int a = 0; a < T; a++) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[i][j];
			}
		}
		fill(&dp[0][0], &dp[100000][3], -1);
		cout << f(0, 0) << "\n";
	}
	return 0;
}