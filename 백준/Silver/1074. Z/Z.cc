#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, r, c;
int ans = -1;

void z(int y, int x, int n) {
	if (n == 0) {
		ans++;
		cout << ans;
		exit(0);
	}

	if (c < x && r < y) {
		z(y - pow(2, n - 2), x - pow(2, n - 2), n - 1);
	}
	else if (c >= x && r < y) { 
		ans += pow(2, n - 1) * pow(2, n - 1);
		z(y -pow(2, n - 2), x +pow(2, n - 2), n - 1);
	}
	else if (c < x && r >= y) {
		ans += (pow(2, n - 1) * pow(2, n - 1)) * 2;
		z(y + pow(2, n - 2), x - pow(2, n - 2), n - 1);
	}
	else if (c >= x && r >= y) {
		ans += (pow(2, n - 1) * pow(2, n - 1)) * 3;
		z(y + pow(2, n - 2), x + pow(2, n - 2), n-1);
	}

}


int main() {
	cin >> N >> r >> c;

	z(pow(2, N - 1), pow(2, N - 1), N);

	return 0;
}