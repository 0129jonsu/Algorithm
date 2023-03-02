#include <iostream>

using namespace std;

int n, s;
int arr[20];
int ans = 0;

void sol(int idx, int sum) {
	sum += arr[idx];
	if (idx == n) return;
	if (sum == s) ans++;
	sol(idx + 1, sum);
	sol(idx + 1, sum - arr[idx]);
}

int main() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sol(0, 0);

	cout << ans;

	return 0;
}