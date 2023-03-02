#include <bits/stdc++.h>

using namespace std;

int N, K;
int visited[100001] = { false, };
int cnt = 0;
int ans = INT_MAX - 1;

void bfs(int n) {
	queue<pair<int, int>> q;
	q.push({ n,0 });


	while (!q.empty()) {
		int curr = q.front().first;
		int c = q.front().second;
		q.pop();
		visited[curr] = true;

		if (ans < c) break;

		if (curr == K) {
			ans = c;
			cnt++;
			continue;
		}

		if (curr * 2 <= 100000 && !visited[curr * 2]) q.push({ curr * 2, c+1 });
		if (curr + 1 <= 100000 && !visited[curr + 1]) q.push({ curr + 1,c+1 });
		if (curr - 1 >= 0 && !visited[curr - 1]) q.push({ curr - 1,c+1 });
	}
}
int main() {
	cin >> N >> K;
	bfs(N);
	cout << ans << "\n";
	cout << cnt << "\n";

	return 0;
}