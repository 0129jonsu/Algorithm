#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	int arr[100001];
	bool a;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int s = 0;
	int e = 1000000000;

	while (s+1 < e) {
		int m = (s + e) / 2;
		int sum = m; int count = 1;

		for (int i = 0; i < N; i++) {
			if (sum - arr[i] < 0) {
				sum = m;
				count++;
			}
			if (sum - arr[i] >= 0) sum -= arr[i];

			if (count > M || arr[i] > m) {
				s = m;
				break;
			}
		}
 		if (s != m) e = m;
	}
	cout << e;

	return 0;
}