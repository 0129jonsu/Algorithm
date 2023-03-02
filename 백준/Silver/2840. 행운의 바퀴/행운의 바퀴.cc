#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int N, K;
	vector<pair<int, char>> v;
	deque<char> dq;

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int tmp1;
		char tmp2;
		cin >> tmp1 >> tmp2;
		v.push_back({ tmp1,tmp2 });
	}

	for (int i = 0; i < N; i++) {
		dq.push_back('?');
	}

	dq.pop_front();
	dq.push_front(v[0].second);
	
	for (int i = 1; i < K; i++) {
		for (int j = 0; j < v[i].first; j++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}

		if (dq.front() == '?' || dq.front() == v[i].second) {
			dq.pop_front();
			dq.push_front(v[i].second);
		}
		else {
			cout << "!";
			return 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (dq[i] != '?' && dq[i] == dq[j]) {
				cout << "!";
				return 0;
			}
		}
	}

	dq.push_back(dq.front());
	dq.pop_front();
	while (!dq.empty()) {
		cout << dq.back();
		dq.pop_back();
	}
	return 0;
}