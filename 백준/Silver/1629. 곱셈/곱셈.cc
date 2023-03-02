#include <iostream>
#include <cmath>

using namespace std;

long long A, B, C;

long long int func(long long int b) {
	if (b == 1) return A % C;

	long long int f = func(b / 2) % C;

	if (b % 2 == 0) return f * f % C;
	else return f * f % C * A % C;
}

int main() {
	cin >> A >> B >> C;

	cout << func(B);

	return 0;
}