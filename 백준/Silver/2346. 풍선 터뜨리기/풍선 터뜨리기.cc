#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N;
	deque<pair<int, int>> dq;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		dq.push_back({ i,tmp });
	}

	for (int i = 0; i < N; i++) {
		int tmp = dq.front().second;
		cout << dq.front().first << " ";
		dq.pop_front();
		if (i == N - 1) break;
		
			if (tmp > 0) {
				for (int j = 0; j < abs(tmp) - 1; j++) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
			}
			else {
				for (int j = 0; j < abs(tmp); j++) {
					dq.push_front(dq.back());
					dq.pop_back();
				}
			}
	}



	return 0;
}