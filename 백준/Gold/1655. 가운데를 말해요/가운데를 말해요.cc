#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	priority_queue<int> pq_1;
	priority_queue<int, vector<int>, greater<int>> pq_2;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (i == 0) m = tmp;
		else if (pq_1.size() >= pq_2.size()) {
			if (tmp > m) pq_2.push(tmp);
			else {
				if (!pq_1.empty() && pq_1.top() >= tmp) {
					pq_1.push(tmp);
					pq_2.push(m);
					m = pq_1.top();
					pq_1.pop();
				}
				else {
					pq_2.push(m);
					m = tmp;
				}
			}
		}
		else if (pq_1.size() < pq_2.size()) {
			if (tmp > m) {
				if (pq_2.top() >= tmp) {
					pq_1.push(m);
					m = tmp;
				}
				else {
					pq_1.push(m);
					m = pq_2.top();
					pq_2.pop();
					pq_2.push(tmp);
				}
			}
			else {
				pq_1.push(tmp);
			}
		}
		cout << m << "\n";
	}
	return 0;
}