#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long N, k;

	cin >> N >> k;

	long long s = 0;
	long long e = N * N;

	while (s <= e) {
		long long m = (s + e) / 2;
		long long cnt = 0;

		for (long long i = 1; i <= N; i++) {
			cnt += min(m / i, N);
		}
		if (cnt >= k) e = m - 1;
		else s = m + 1;
	}

	cout << s;

	return 0;
}