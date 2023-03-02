#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100001];

int his(int l, int r) {
	if (l == r) return arr[l];

	int mid = (l + r) / 2;
	int lm = mid;
	int rm = mid + 1;

	int maxv = max(his(l, lm), his(rm, r));

	int d = 2; // 밑변
	int h = min(arr[lm], arr[rm]); // 높이

	maxv = max(maxv, d * h);

	while (l<lm || r>rm) {
		if (r > rm && (l == lm || arr[rm+1] > arr[lm-1])) {//오른쪽
			d++;
			h = min(h, arr[++rm]);
		}
		else {
			d++;
			h = min(h, arr[--lm]);
		}
		maxv = max(maxv, d * h);
	}

	return maxv;

}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cout << his(1, N);

	return 0;
}