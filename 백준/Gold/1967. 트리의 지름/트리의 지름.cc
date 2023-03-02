#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[100002];
bool visited[100002];
int V, e;
int ans = 0;

void dfs(int start, int d) {
	if (visited[start]) return;
	visited[start] = true;
	if (ans < d) {
		ans = d;
		e = start;
	}

	int size = tree[start].size();
	for (int i = 0; i < size; i++) {
		int next = tree[start][i].first;
		if (!visited[next]) dfs(next, d + tree[start][i].second);
	}
}

int main() {
	fill(visited, visited + 100002, false);
	cin >> V;

	for (int i = 0; i < V-1; i++) {
		int node, n_node, dis;
		cin >> node >> n_node >> dis;
		tree[node].push_back({ n_node, dis });
		tree[n_node].push_back({ node, dis });
		}
	dfs(1, 0);
	fill(visited, visited + 100002, false);
	dfs(e, 0);

	cout << ans << "\n";

	return 0;
}