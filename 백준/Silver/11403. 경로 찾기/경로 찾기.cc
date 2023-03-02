#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> graph[101];
priority_queue<int, vector<int>, greater<int>> q;
bool visited[101];

void dfs(int start) {
	if (visited[start]) return;
	int size = graph[start].size();
	for (int i = 0; i < size; i++) {
		int next = graph[start][i];
		if (next == 0) break;
		else {
			visited[start] = true;
			q.push(next);
			dfs(next);
		}
	}
}

int main() {
	for (int b = 0; b < 101; b++) {
		graph[b].clear();
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) graph[i].push_back(j);

		}
	}

	for (int i = 1; i <= N; i++) {
		fill(visited, visited + 101, false);
		dfs(i);
		for (int j = 1; j <= N; j++) {
			if (!q.empty()) {
				if (q.top() == j) {
					cout << 1 << " ";
					while(!q.empty()&&q.top() == j)
						q.pop();
				}
				else cout << 0 << " ";
			}
			else cout << 0 << " ";
		}
		cout << "\n";
	}
	return 0;
}