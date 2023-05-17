#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	if (N + M - 1 <= K) cout << "YES" << "\n";
	else {
		cout << "NO";
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << i + j - 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}