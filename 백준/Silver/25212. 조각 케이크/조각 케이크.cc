#include <bits/stdc++.h>

using namespace std;

int N;
double arr[26];
int ans = 0;

void f(int n, double sum) {
	sum += 1/arr[n];
	if (n == N) return;
	if (0.99 <= sum && sum <= 1.01) ans++;
	f(n + 1, sum);
	f(n + 1, sum - 1/arr[n]);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	f(0, 0.0);

	cout << ans << "\n";

	return 0;
}