#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> v1, v2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
		v2.push_back(tmp);
	}

	sort(v2.begin(), v2.end());
	v2.resize(unique(v2.begin(), v2.end()) - v2.begin());

	for (int x : v1) {
		int tmp = lower_bound(v2.begin(), v2.end(), x) - v2.begin();
		cout << tmp << ' ';
	}

	return 0;
}