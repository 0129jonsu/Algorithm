#include <iostream>
#include <vector>
#include <queue>



using namespace std;

int N, E, v1, v2;
vector<pair<int, long long>> graph[801];
priority_queue<pair<int, long long>> pq;
long long d[801];
long long mmm = 10000000000;

void f(int start) {
	pq.push({ start,d[start] });

	while (!pq.empty()) {
		int curr = pq.top().first;
		long long curr_cost = pq.top().second;
		pq.pop();
		if (curr_cost > d[curr]) continue;

		int size = graph[curr].size();

		for (int i = 0; i < size; i++) {
			int next = graph[curr][i].first;
			long long next_cost = d[curr] + graph[curr][i].second;

			if (next_cost < d[next]) {
				d[next] = next_cost;
				pq.push({ next, next_cost });
			}
		}
	}
}

int main() { // 1 -> v1 -> v2 -> N
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(d, d + 801, mmm);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	d[1] = 0;
	cin >> v1 >> v2;

	f(1);
	long long ov1 = d[v1];
	long long ov2 = d[v2];

	fill(d, d + 801, mmm);
	d[v1] = 0;
	f(v1);
	long long v1N = d[N];
	long long v1v2 = d[v2];

	fill(d, d + 801, mmm);
	d[v2] = 0;
	f(v2);
	long long v2N = d[N];
	long long v2v1 = d[v1];

	long long tmp = mmm;
	tmp = min(ov1 + v1v2 + v2N, tmp);
	tmp = min(ov2 + v2v1 + v1N, tmp);
	if (ov1 == mmm || ov2 == mmm || v2N == mmm || v1N ==mmm) cout << -1;
	else cout << tmp;

	return 0;
}