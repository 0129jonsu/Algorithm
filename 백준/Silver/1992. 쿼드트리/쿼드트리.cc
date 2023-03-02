#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
int arr[64][64];
int a = 0;

void qt(int y, int x, int n) {
	if (n == 1) {
		cout << arr[y][x];
		return;
	}

	bool z = true;
	bool o = true;

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j]) z = false;
			else o = false;
		}
	}

	if (z) cout << 0;
	else if (o) cout << 1;
	else {
		cout << "(";
		qt(y, x, n / 2);
		qt(y, x + n / 2, n / 2);
		qt(y + n / 2, x, n / 2);
		qt(y + n / 2, x + n / 2, n / 2);
		cout << ")";
	}
	return;

}

int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}

	qt(0, 0, N);

	return 0;
}