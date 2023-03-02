#include <bits/stdc++.h>

using namespace std;

int N, M;
int p1, p2;
int m[101][101];
bool visited[101] = { 0, };
queue<int> q;
int ans = 0;
int d[101];

void bfs(int n) {
	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (m[curr][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
				d[i] = d[curr] + 1;
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> p1 >> p2;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		m[u][v] = 1;
		m[v][u] = 1;
	}

	bfs(p1);

	if (d[p2] == 0) cout << -1 << "\n";
	else cout << d[p2] << "\n";

	return 0;
}