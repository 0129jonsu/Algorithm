#include <bits/stdc++.h>

using namespace std;

int N, M;
int m[1001][1001];
bool visited[1001];
int ans = 0;


void dfs(int n) {
	visited[n] = true;
	for (int i = 1; i <= N; i++) {
		if (m[n][i] == 1 && !visited[i]) dfs(i);

	}
}

int main() {
	cin >> N >> M;
	fill(visited, visited + 1001, false);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		m[u][v] = 1;
		m[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	dfs(1);
	cout << ans << "\n";


	return 0;
}