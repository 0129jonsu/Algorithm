#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[2001];
int dp[2001][2001];

void f() {
	for (int i = 0; i < N; i++) {
		for (int s = 1; s + i <= N; s++) {
			int e = s + i;
			if (s == e) {
				dp[s][e] = 1;
				continue;
			}
			if (s + 1 == e) {
				if (arr[s] == arr[e]) dp[s][e] = 1;
				else dp[s][e] = 0;
				continue;
			}
			if (arr[s] == arr[e] && dp[s + 1][e - 1] == 1) dp[s][e] = 1;
			else dp[s][e] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dp[0][0], &dp[2000][2001], -1);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	f();
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		cout << dp[start][end] << "\n";
	}

	return 0;
}