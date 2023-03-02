#include <bits/stdc++.h>

using namespace std;

int T, L;
int x_1, y_1;
int x_2, y_2;
bool visited[301][301];
int dx[] = { 2,1,-1,-2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
queue<pair<int, int>> q;
int d[301][301];

void bfs(int y, int x) {
	visited[y][x] = true;
	q.push({ y,x });

	while (!q.empty()) {
		int curr_y = q.front().first;
		int curr_x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = curr_y + dy[i];
			int nx = curr_x + dx[i];

			if (ny < 0 || ny >= L || nx < 0 || nx >= L) continue;

			if (!visited[ny][nx]) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
				d[ny][nx] = d[curr_y][curr_x] + 1;
			}
		}
	}
}

int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> L;
		cin >> x_1 >> y_1;
		cin >> x_2 >> y_2;

		fill(&visited[0][0], &visited[300][301], false);
		fill(&d[0][0], &d[300][301], 0);
		bfs(y_1, x_1);

		cout << d[y_2][x_2] << "\n";
		while (!q.empty()) q.pop();
	}

	return 0;
}