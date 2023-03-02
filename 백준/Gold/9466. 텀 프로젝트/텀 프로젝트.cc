#include <iostream>
#include <vector>

using namespace std;

int T, n;
int tmp;
int ans = 0;
int cnt = 0;
int v1[100001];
bool visited[100001];
bool finished[100001];

void dfs(int n) {
	visited[n] = true;

	if (visited[v1[n]] && !finished[v1[n]]) {
		for (int i = v1[n]; n != i; i = v1[i]) ans++;
		ans++;
	}
	if(!visited[v1[n]]) dfs(v1[n]);

	finished[n] = true;
}

int main() {
	cin >> T;
	for (int a = 0; a < T; a++) {
		fill(&visited[0], &visited[100001], false);
		fill(&finished[0], &finished[100001], false);;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> v1[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) dfs(i);
		}
		cout << n - ans << "\n";
		ans = 0;
	}

	return 0;
}