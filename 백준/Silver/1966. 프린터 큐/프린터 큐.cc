#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		int N, M;
		int cnt = 0;
		bool a = false;
		pair<int, int> ans;
		cin >> N >> M;
		queue<pair<int, int>> q;
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			q.push({ j,tmp });
			if (j == M) ans = { j,tmp };
		}
		while (!a) {
			int qm = 0;
			for (int x = 0; x < q.size(); x++) {
				qm = max(qm, q.front().second);
				q.push(q.front());
				q.pop();
			}

			for (int x = 0; x < q.size(); x++) {
				if (qm == q.front().second) {
					cnt++;
					if (q.front() == ans) {
						cout << cnt << "\n";
						a = true;
						break;
					}
					q.pop();
					break;
				}
				else {
					q.push(q.front());
					q.pop();
				}
			}
		}
	}

	return 0;
}