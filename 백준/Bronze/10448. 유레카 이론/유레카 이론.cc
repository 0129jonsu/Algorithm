#include <iostream>

using namespace std;

int t_n(int n) {
	return n * (n + 1) / 2;
}

int main() {
	int c;
	int test[1000];
	bool a;

	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> test[i];
	}

	for (int i = 0; i < c; i++) {
		a = false;
		for (int x = 1; t_n(x) <= test[i] && a == false; x++)
			for (int y = 1; t_n(y) + t_n(x) <= test[i] && a == false; y++) {
				for (int z = 1; t_n(z) + t_n(y) + t_n(x) <= test[i] && a == false; z++) {
					if (t_n(z) + t_n(y) + t_n(x) == test[i]) a = true;
				}
			}
		cout << a;
		if (i != c - 1) {
			cout << "\n";
		}
	}



	return 0;
}
