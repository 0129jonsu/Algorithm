#include <iostream>
#include <queue>

using namespace std;

int N, M;
int a[101][101];
bool visited[101][101];
int ans[101][101] = { 1, };
queue<pair<int, int>> q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int x, int y) {
	visited[y][x] = true;
	q.push({ y, x });

	while (!q.empty()) {
		int curr_y = q.front().first;
		int curr_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = curr_x + dx[i];
			int yy = curr_y + dy[i];

			if (xx >= M || xx < 0 || yy >= N || yy < 0) continue;

			if (a[yy][xx] == 1 && !visited[yy][xx]) {
				q.push({ yy,xx });
				visited[yy][xx] = true;
				ans[yy][xx] = ans[curr_y][curr_x] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < M; j++) {
			a[i][j] = st[j] - '0';
		}
	}

	bfs(0, 0);

	cout << ans[N-1][M-1] << "\n";

	return 0;
}