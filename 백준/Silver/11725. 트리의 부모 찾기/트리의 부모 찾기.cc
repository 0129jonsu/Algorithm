#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> graph[100001];
int ans[100001];
bool visited[100001];

void f(int start) {
	if (visited[start]) return;
	visited[start] = true;
	int size = graph[start].size();

	for (int i = 0; i < size; i++) {
		int next = graph[start][i];
		if (!visited[next]) {
			ans[next] = start;
			f(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;


	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	f(1);
	for (int i = 2; i <= N; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}