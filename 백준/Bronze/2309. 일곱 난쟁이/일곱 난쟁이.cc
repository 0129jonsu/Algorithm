#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[9];
	int index = 0;
	int x = 0;
	int p = -1, q = -1;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		x += arr[i];
	}
	x -= 100;
	sort(arr, arr + 9);

	for (int j = 0; j < 9; j++) {
		for (int k = j; k < 8; k++) {
			if (arr[j] + arr[k + 1] == x) {
				p = j;
				q = k + 1;
			}
		}
	}

	for (int y = 0; y < 9; y++) {
		if (y == p || y == q) {

		}
		else cout << arr[y] << "\n";
	}

	return 0;
}