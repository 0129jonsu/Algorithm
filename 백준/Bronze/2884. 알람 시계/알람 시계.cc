#include <iostream>

using namespace std;

int main() {
	int hr1, min1;
	cin >> hr1 >> min1;

	if (min1 < 45) {
		min1 = 60 - (45 - min1);
		if (hr1 != 0) hr1 = hr1 - 1;
		else hr1 = 23;
	}
	else {
		min1 = min1 - 45;
	}

	cout << hr1 << " " << min1;

	return 0;
}