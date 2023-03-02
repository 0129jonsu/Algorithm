#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int sch[100];
	int pl[100] = { NULL };
	int ans = 0;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> sch[i];
	}

	for (int i = 0; i < k; i++) {
		bool in = false;

		for (int j = 0; j < n; j++) {
			if (pl[j] == sch[i]) {
				in = true;
				break;
			}
		}
		if (in) continue;

		for (int j = 0; j < n; j++) {
			if (pl[j] == NULL) {
				pl[j] = sch[i];
				in = true;
				break;
			}
		}
		if (in) continue;

		int idx = 0;
		int idx_m = 0;
		for (int j = 0; j < n; j++) {
			int  count = 0;
			for (int x = i + 1; x < k; x++) {
				if (pl[j] == sch[x]) break;

				count++;
			}

			if (count > idx_m) {
				idx = j;
				idx_m = count;
			}
		}
		pl[idx] = sch[i];
		ans++;
	}

	cout << ans;

	return 0;
}