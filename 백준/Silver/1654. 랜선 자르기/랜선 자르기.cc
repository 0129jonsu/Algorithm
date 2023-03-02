#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int K, N;
	int arr[10001];
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}

	long long s = 0;
	long long e = 9223372036854775807;

	while (s <= e) {
		long long m = (s + e) / 2;
		long long cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += arr[i] / m;
		}
		if (cnt >= N) s = m + 1;
		else e = m - 1;
	}
	cout << e;

	return 0;
}