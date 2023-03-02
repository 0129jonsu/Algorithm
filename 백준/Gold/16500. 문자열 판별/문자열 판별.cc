#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	string A[101];
	int N;
	int dp[101] = { 0, };

	cin >> S >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	dp[S.size()] = 1;
	
	for (int i = S.size() - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (S.find(A[j],i) == i && dp[i + A[j].size()] == 1) {
				dp[i] = 1;
				break;
			}
		}
	}

	cout << dp[0] << "\n";

	return 0;
}