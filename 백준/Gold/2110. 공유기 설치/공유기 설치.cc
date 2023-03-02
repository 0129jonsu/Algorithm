#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, C;
	vector<int> v;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int s = 0;
	int e = v.back();

	while (s <= e) {
		int cnt = 1;
		int idx = 0;
		int m = (s + e) / 2;

		for (int i = 1; i < N; i++) {
			if (v[i] - v[idx] >= m) {
				idx = i;
				cnt++;
			}
		}
		if (cnt >= C) s = m + 1;
		else  e = m - 1;
	}
	cout << e;

	return 0;
}