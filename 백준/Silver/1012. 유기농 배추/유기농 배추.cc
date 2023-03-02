#include <bits/stdc++.h>

using namespace std;

int T, M, N, K;
int ma[51][51];
bool visited[51][51];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


void dfs(int cur_n, int cur_m) {
	visited[cur_n][cur_m] = true;
	for (int i = 0; i < 4; i++) {
		int mm = cur_m + dx[i];
		int nn = cur_n + dy[i];
		
		if (mm < 0 || mm >= M || nn < 0 || nn > N) continue;

		if (ma[nn][mm] == 1 && visited[nn][mm] == 0) dfs(nn, mm);
	}
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		fill(&visited[0][0], &visited[50][51], 0);
		fill(&ma[0][0], &ma[50][51], 0);

		cin >> N >> M >> K;

		for (int j = 0; j < K; j++) {
			int n, m;
			cin >> n >> m;
			ma[n][m] = 1;
		}
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (ma[j][k] == 1 && visited[j][k] == 0) {
					dfs(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}