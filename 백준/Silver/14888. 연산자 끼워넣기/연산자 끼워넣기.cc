#include <iostream>

using namespace std;

int N;
int num[12];
int oper[4];
int ans_max = -1000000000;
int ans_min = 1000000000;

void f(int cnt, int res) {
	if (cnt == N-1) {
		ans_max = max(ans_max, res);
		ans_min = min(ans_min, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) { // + - * /
			oper[i]--; 
			if (i == 0) f(cnt + 1, res + num[cnt + 1]);
			else if (i == 1) f(cnt + 1, res - num[cnt + 1]);
			else if (i == 2) f(cnt + 1, res * num[cnt + 1]);
			else if (i == 3) f(cnt + 1, res / num[cnt + 1]);
			oper[i]++;
		}
	}
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	f(0, num[0]);

	cout << ans_max << "\n" << ans_min;
	return 0;
}