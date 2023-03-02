#include <bits/stdc++.h>

using namespace std;

int N, K;
bool visited[100001] = { false, };
int d[100001] = { 0, };


void bfs(int n) {
	deque<int> dq;
	visited[n] = true;
	dq.push_back(n);

	while (!dq.empty()) {
		int curr = dq.front();
		dq.pop_front();

		if (curr == K) {

			return;
		}
		if (curr * 2 < 100001 && !visited[curr * 2]) {
			dq.push_front(curr * 2);
			visited[curr * 2] = true;
			d[curr * 2] = d[curr];
		}
		if (curr + 1 < 100001 && !visited[curr + 1]) {
			dq.push_back(curr + 1);
			visited[curr + 1] = true;
			d[curr + 1] = d[curr] + 1;
		}
		if (curr - 1 >= 0 && !visited[curr - 1]) {
			dq.push_back(curr - 1);
			visited[curr - 1] = true;
			d[curr - 1] = d[curr] + 1;
		}
		
	}
}

int main() {
	cin >> N >> K;

	bfs(N);
	cout << d[K];

	return 0;
}