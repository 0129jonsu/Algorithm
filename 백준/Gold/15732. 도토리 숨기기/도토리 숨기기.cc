#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, K, D;
	int A[10001], B[10001], C[10001];

	cin >> N >> K >> D;
	for (int i = 0; i < K; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}

	int s = 0;
	int e = N;
	int res = 0;

	while (s <= e) {
		long long cnt = 0;
		int m = (s + e) / 2;

		for (int i = 0; i < K; i++) {
			int k = min(m, B[i]);
			if(k >= A[i]) cnt += ((k - A[i]) / C[i] + 1);
		}
		if (cnt >= D) {
			res = m;
			e = m - 1;
		}
		else s = m + 1;

	}

	cout << res;

	return 0;
}