#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
bool visited[1001];
vector<int> graph[1001];
queue<int> q;

void dfs(int start) {
	if (visited[start]) return;
	visited[start] = true;
	cout << start << " ";
	int size = graph[start].size();
	for (int i = 0; i < size; i++) {
		int next = graph[start][i];
		dfs(next);
	}
}

void bfs(int start) {
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		cout << s << " ";
		int size = graph[s].size();
		for (int i = 0; i < size; i++) {
			int next = graph[s][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}


int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	fill(visited, visited + 1001, false);
	cout << "\n";
	bfs(V);


	return 0;
}