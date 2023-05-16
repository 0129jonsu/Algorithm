#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int odd_ans = 2000000001;
int even_ans = 2000000001;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if ((v[j] - v[i]) % 2 != 0)odd_ans = min(odd_ans, v[j] - v[i]);
			else even_ans = min(even_ans, v[j] - v[i]);
		}
	}

	if (odd_ans == 2000000001) odd_ans = -1;
	if (even_ans == 2000000001) even_ans = -1;

	cout << even_ans << " " << odd_ans;

	return 0;
}