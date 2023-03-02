#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, s, e;
vector<pair<int, int>> graph[1001];
priority_queue<pair<int, int>> pq;
int d[1001];

void f(int start) {
	pq.push({ start,0 });

	while (!pq.empty()) {
		int curr = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (d[curr] < cost) continue;

		int size = graph[curr].size();
		for (int i = 0; i < size; i++) {
			int next = graph[curr][i].first;
			int next_cost = d[curr] + graph[curr][i].second;

			if (d[next] > next_cost) {
				d[next] = next_cost;
				pq.push({ next, next_cost });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	fill(d, d + 1001, 1000000000);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> s >> e;
	d[s] = 0;
	f(s);

	cout << d[e];

	return 0;
}