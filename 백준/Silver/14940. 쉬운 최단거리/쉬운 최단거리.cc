#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int gx, gy;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 2) {
				gx = j;
				gy = i;
				q.push({ j,i });
				visited[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
			if (!visited[next_y][next_x] && map[next_y][next_x] == 1) {
				q.push({ next_x,next_y });
				visited[next_y][next_x] = visited[curr_y][curr_x] + 1;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && (i != gy || j != gx) && map[i][j] == 1) visited[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}