#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M;
	vector<int> v;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (v[i] + v[j] + v[k] <= M) ans = max(ans, v[i] + v[j] + v[k]);
			}
		}
	}

	cout << ans;



	return 0;
}