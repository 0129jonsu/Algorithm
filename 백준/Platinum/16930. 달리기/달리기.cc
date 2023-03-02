#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, x11, x22, y11, y22;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
char map[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
int mmm = 2000000000;

int f() {
	q.push({ x11,y11 });
	visited[y11][x11] = 0;
	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= K; j++) {
				int xx = curr_x + dx[i] * j;
				int yy = curr_y + dy[i] * j;
				if (xx > M || xx <= 0 || yy > N || yy <= 0 || map[yy][xx] == '#' || visited[yy][xx] < visited[curr_y][curr_x] + 1) break;

				if (visited[yy][xx]==mmm) {
					visited[yy][xx] = visited[curr_y][curr_x] + 1;
					q.push({ xx,yy });
				}
			}
		}
	}
	return visited[y22][x22];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char a;
			cin >> a;
			map[i][j] = a;
			visited[i][j] = mmm;
		}
	}
	cin >> y11 >> x11 >> y22 >> x22;

	int ans = f();

	if (ans == mmm) cout << -1;
	else cout << ans;

	return 0;
}