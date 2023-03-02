#include <iostream>
#include <queue>

using namespace std;

int M, N;
int ans = 0;
int t[1001][1001];
int m[1001][1001];
queue<pair<int, int>> q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs() {
	while (!q.empty()) {
		int curr_y = q.front().first;
		int curr_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = curr_y + dy[i];
			int xx = curr_x + dx[i];

			if (xx >= M || xx < 0 || yy >= N || yy < 0) continue;

			if (t[yy][xx] == 0) {
				q.push({ yy,xx });
				t[yy][xx] = 1;
				m[yy][xx] = m[curr_y][curr_x] + 1;
			}
		}
	}

}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			t[i][j] = tmp;
			if (tmp == 1) {
				q.push({ i,j });
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (t[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			else ans = max(ans, m[i][j] );
		}
	}
	
	cout << ans << "\n";

	return 0;
}