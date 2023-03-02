#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long N, M;
	long long v[100001];
	long long s = 0;
	long long e = 0;
	long long res;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		e += v[i];
	}

	while (s+1 < e) {
		long long count = M;
		long long tmp1 = 0;
		int m = (s + e) / 2;
		if (M == 1) {
			int sum = 0;
			for (int i = 0; i < N; i++) {
				sum += v[i];
			}
			cout << sum;
			return 0;
		}

			for (int j = 0; j < N; j++) {
				if (count == 0) {
					s = m;
					break;
				}
				tmp1 += v[j];
				if (tmp1 >= m) {
					count--;
					tmp1 = 0;
					j--;
					continue;
				}
			}

		if (count != 0) e = m;

		res = s;
	}

	cout << res;


	return 0;
}