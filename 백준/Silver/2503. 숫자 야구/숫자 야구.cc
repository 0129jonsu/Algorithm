#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	bool a[1000] = { false };
	int c;
	cin >> c;

	for (int p = 0; p < c; p++) {
		int num, strike, ball;
		cin >> num >> strike >> ball;
		
		for (int i = 123; i <= 987; i++) {
			if (a[i]) continue;

			string str = to_string(i);
			if ((str[0] == '0' || str[1] == '0' || str[2] == '0') || (str[0] == str[1] || str[1] == str[2] || str[0] == str[2])) {
				a[i] = true;
				continue;
			}

			int s = 0, b = 0;
			string tmp = to_string(num);
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if (str[x] == tmp[y]) {
						if (x == y) s++;
						else b++;
					}
				}
			}

			if (strike == s && ball == b) a[i] = false;
			else a[i] = true;
		}
	}

	int ans = 0;
	for (int i = 123; i <= 987; i++) {
		if (!a[i]) ans++;
	}
	cout << ans;

	return 0;
}