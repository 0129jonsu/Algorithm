#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;
int f[1000001];
int visited[1000001];
int ans = 0;
int d[1000001] = { 0, };
queue<int> q;

void bfs(int n) {
	int e[] = { U,D };
	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nf;
			if (i == 0) nf = curr + e[i];
			else nf = curr - e[i];

			if (nf < 1 || nf > F) continue;

			if (!visited[nf]) {
				q.push(nf);
				visited[nf] = true;
				d[nf] = d[curr] + 1;
			}
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	if (S == G) {
		cout << 0 << "\n";
		return 0;
	}
	bfs(S);
	
	if (d[G] == 0) cout << "use the stairs" << "\n";
	else cout << d[G] << "\n";

	return 0;
}