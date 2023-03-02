#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int ans = 0;
	int tmp_min = INT_MAX - 1;
	int tmp_ans = 0;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp_min > tmp) tmp_min = tmp;
		if (tmp - tmp_min > tmp_ans) tmp_ans = tmp - tmp_min;
		cout << tmp_ans << " ";
	}

	return 0;
}