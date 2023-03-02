#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N, M;
	int arr[51];
	int cnt = 0;
	deque<int> dq;

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {;
		dq.push_back(i);
	}
	
	for (int i = 1; i <= M; i++) {
		auto tmp = find(dq.begin(), dq.end(), arr[i]);
		if (dq.front() == arr[i]) {
			dq.pop_front();
			continue;
		}
		if (tmp - dq.begin() > dq.size() / 2) {
			while (dq.front() != arr[i]) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		else {
			while (dq.front() != arr[i]) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		dq.pop_front();
	}
	cout << cnt;

	return 0;
}