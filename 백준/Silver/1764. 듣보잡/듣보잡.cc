#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> dv;
	vector<string> v;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		dv.push_back(tmp);
	}

	sort(dv.begin(), dv.end());

	for (int i = 0; i < M; i++) {

		string tmp;
		cin >> tmp;

		int s = 0;
		int e = dv.size();
		
		while (s <= e) {
			int m = (s + e) / 2;
			if (dv.size() <= m) break;
			if (tmp == dv[m]) {
				v.push_back(tmp);
				break;
			}
			if (tmp > dv[m]) s = m + 1;
			else if (tmp <= dv[m]) e = m - 1;

		}
	}

	sort(v.begin(), v.end());
	int sz = v.size();
	cout << sz << "\n";
	for (int i = 0; i < sz; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}