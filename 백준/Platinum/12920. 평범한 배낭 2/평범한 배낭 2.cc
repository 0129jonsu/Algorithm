#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> arr;
int dp[10001][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	fill(&dp[0][0], &dp[10000][10001], 0);

	cin >> N >> M;

	int cnt = 0;
	bool check = false;

	arr.push_back({ 0,0 });

	for (int k = 0; k < N; k++) {
		int V, C, K;
		cin >> V >> C >> K;

		for (int j = K; j > 0; j >>= 1) {
			int n = j - (j >> 1);
			arr.push_back({ V * n, C * n });
			cnt++;
		}
	}

	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= M; j++) {
			if (j >= arr[i].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[cnt][M];


	return 0;
}