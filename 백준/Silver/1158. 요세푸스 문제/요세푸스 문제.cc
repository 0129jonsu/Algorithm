#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N, K;
	deque<int> dq;
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	cout << "<";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < K; j++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		if (i == N) cout << dq.front();
		else cout << dq.front() << ", ";
		dq.pop_front();
	}
	cout << ">";


	return 0;
}