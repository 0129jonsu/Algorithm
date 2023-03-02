#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100001];

long long pa(int l, int r) {
	if (l == r) return arr[l] * arr[l];

	int mid = (l + r) / 2;

	int lm = mid;
	int rm = mid + 1;
	long long ans = max(pa(l, lm), pa(rm, r));

	long long minv = min(arr[lm], arr[rm]);
	long long sum = arr[lm] + arr[rm];

	ans = max(ans, sum * minv);

	while (l<lm || r>rm) {
		if (r > rm && (lm == l || arr[rm + 1] > arr[lm - 1])) {
			sum += arr[++rm];
			minv = min(minv, arr[rm]);
		}
		else {
			sum += arr[--lm];
			minv = min(minv, arr[lm]);
		}
		ans = max(ans, sum * minv);
	}
	 
	return ans;
}
 
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cout << pa(1, N);

	return 0;
}