#include <bits/stdc++.h>

using namespace std;

long long A, B;
int ans = 1;

int main() {
	cin >> A >> B;

	while (A != B) {
		if (B == 0 || (B % 2 == 1 && B % 10 != 1)) {
			cout << "-1" "\n";
			return 0;
		}
		if (B % 2 == 1) B /= 10;
		else B /= 2;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}