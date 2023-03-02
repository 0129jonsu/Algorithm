#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cb[20];
int ans = 0;

void fill(int l , int w, int h, int idx) {
	bool ept = false;
	if (l == 0 || w == 0 || h == 0) {
		return;
	}

	idx = log2(min({ l,w,h }));
	
	for (int i = idx; i >= 0; i--) {
		if (cb[i] > 0) {
			idx = i;
			ept = true;
			break;
		}
	}

	if (!ept) {
		cout << "-1";
		exit(0);
	}

	int cs = pow(2, idx);
	ans++;
	cb[idx]--;

	fill(l - cs, cs, h, idx);
	fill(l, w - cs, h, idx);
	fill(cs, cs, h - cs, idx);
}

int main() {
	int length, width, height;
	int N;
	int tmp1, tmp2;

	cin >> length >> width >> height;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		cb[tmp1] = tmp2;
	}
	
	fill(length, width, height, N - 1);

	cout << ans;

	return 0;
}