#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		bool ch = false;
		int a;
		cin >> a;

		int s = 0;
		int e = N - 1;

		while (s <= e) {
			int m = (s + e) / 2;
			if (v[m] > a) e = m - 1;
			else if (v[m] < a) s = m + 1;
			else if (v[m] == a) {
				cout << "1" << "\n";
				ch = true;
				break;
			}
		}
		if (!ch) cout << "0" << "\n";
	}

	return 0;
}