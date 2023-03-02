#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

int main() {
	int N, d, w;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hw;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> hw2;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		hw.push({ d,w });
	}

	for (int i = 0; i < N; i++) {
		if (hw.top().first <= hw2.size()) {
			if (hw.top().second > hw2.top().second) {
				hw2.pop();
				hw2.push(hw.top());
				hw.pop();
			}
			else hw.pop();
		}
		else {
			hw2.push(hw.top());
			hw.pop();
		}
	}

	int sz = hw2.size();
	int ans = 0;

	for (int i = 0; i < sz; i++) {
		ans += hw2.top().second;
		hw2.pop();
	}

	cout << ans;

	return 0;
}