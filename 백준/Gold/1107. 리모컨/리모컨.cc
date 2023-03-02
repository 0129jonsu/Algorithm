#include <bits/stdc++.h>

using namespace std;

bool arr[10];

int f(int n) {
	if (n == 0) {
		if (!arr[0]) return 0;
		else return 1;
	}
	int c = 0;
	while (n > 0) {
		if (!arr[n % 10]) return 0;

		n /= 10;
		c++;
	}
	return c;
}

int main() {
	int N, M;
	cin >> N >> M;

	fill(arr, arr + 10, true);

	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp] = false;
	}

	int ans = abs(N - 100);

	for (int i = 0; i <= 999999; i++) {
		int cnt = f(i);
		if (cnt > 0) {
			int cnt_2 = abs(i - N);
			if (ans > cnt + cnt_2) ans = cnt + cnt_2;
		}
	}
	cout << ans;

	return 0;
}