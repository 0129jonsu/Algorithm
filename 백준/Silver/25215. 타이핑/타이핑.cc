#include <bits/stdc++.h>

using namespace std;

int main() {
	string st;
	cin >> st;
	bool shift = false;
	int ans = 0;

	for (int i = 0; i < st.size(); i++) {
		ans++;

		if (st[i] >= 'a' && st[i] <= 'z') {
			if (!shift) continue;
			else if (shift) {
				ans++;
				if (st[i + 1] >= 'A' && st[i + 1] <= 'Z');
				else shift = false;
			}
		}

		else {
			if (shift) continue;
			else if (!shift) {
				ans++;
				if (st[i + 1] >= 'a' && st[i + 1] <= 'z');
				else shift = true;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}