#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[100000];
	int n;
	int tmp[100000];


	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	tmp[0] = arr[0];
	int ans = tmp[0];

	for (int i = 1; i < n; i++) {
		tmp[i] = max(tmp[i - 1] + arr[i], arr[i]);
		ans = max(tmp[i], ans);
	}

	cout << ans;

	return 0;
}