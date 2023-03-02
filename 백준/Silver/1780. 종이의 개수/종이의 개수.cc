#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int ans0 = 0, ans1 = 0, ans_1 = 0;
short v[2187][2187];

void cut(int s1, int s2, int n) {
	if (n == 0) return;

	int idx1 = s1;
	int idx2 = s2;

	int sum = 0;
	int zz = 0;

	int tmp = v[idx1][idx2];
	for (int i = idx1; i < idx1 + n; i++) {
		for (int j = idx2; j < idx2 + n; j++) {
			if (tmp != v[i][j]) break;
			sum += v[i][j];
			if (v[i][j] == 0) zz++;
			
		}
	}

	if (sum == n * n) ans1++;
	else if (sum == -(n * n)) ans_1++;
	else if (zz == n * n) ans0++;

	else {
		if (n == 1)return;
		for (int i = idx1; i < idx1+n; i += n / 3) {
			for (int j = idx2; j < idx2+n; j += n / 3) {
				cut(i, j, n/3);
			}
		}
		
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	cut(0, 0, N);

	cout << ans_1 << endl;
	cout << ans0 << endl;
	cout << ans1 << endl;

	return 0;
}