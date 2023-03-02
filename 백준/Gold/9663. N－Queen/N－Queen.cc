#include <iostream>

using namespace std;

int N;
int cnt = 0;
int q[15];

bool check(int n) {
	for (int i = 0; i < n; i++) {
		if (q[i] == q[n] || n - i == abs(q[n] - q[i])) return false;
	}
	return true;

}

void queen(int n) {
	if (n == N) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			q[n] = i;
			if (check(n)) queen(n + 1);
		}
	}
}

int main() {
	cin >> N;

	queen(0);
	cout << cnt;

	return 0;
}