#include <bits/stdc++.h>

using namespace std;

int main() {
	string st;
	string tmp;
	int ans = 0;
	bool ism = false;
	vector<string> v;
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] == 0) continue;

		if (ism) {
			if (st[i] != '+' || st[i] != '-') tmp += st[i];
			if (st[i] == '+' || st[i] == '-' || i == st.size() - 1) {
				ans -= stoi(tmp);
				tmp = "";
			}
		}
		else {
			if (st[i] == '-') {
				ans += stoi(tmp);
				tmp = "";
				ism = true;
				continue;
			}

			if (st[i] != '+') tmp += st[i];
			if (st[i] == '+' || i == st.size() - 1) {
				ans += stoi(tmp);
				tmp = "";
			}

		}
	}

	cout << ans;

	return 0;
}