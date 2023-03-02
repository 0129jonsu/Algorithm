#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int d[1001];
int pre[1001];
priority_queue<pair<int, int>> pq;
stack<int> q;

void f(int start) {
	pq.push({ start,d[start] });

	while (!pq.empty()) {
		int curr = pq.top().first;
		int curr_cost = pq.top().second;
		pq.pop();

		if (d[curr] < curr_cost) continue;
		int size = graph[curr].size();
		for (int i = 0; i < size; i++) {
			int next = graph[curr][i].first;
			int next_cost = d[curr] + graph[curr][i].second;

			if (d[next] > next_cost) {
				d[next] = next_cost;
				pq.push({ next, next_cost });
				pre[next] = curr;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	int s, e;
	cin >> s >> e;

	fill(d, d + 1001, 1000000000);
	d[s] = 0;
	f(s);
	cout << d[e] << "\n";

	int tmp = e;
	while(tmp != s){
		q.push(tmp);
		tmp = pre[tmp];
	}
	q.push(s);


	cout << q.size() << "\n";
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}

	return 0;
}