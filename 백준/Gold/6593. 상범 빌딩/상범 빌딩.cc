#include <bits/stdc++.h>

using namespace std;

int L = -1, R = -1, C = -1;
int start_x, start_y, start_h;
int end_x, end_y, end_h;

char m[31][31][31];
bool visited[31][31][31];
int d[31][31][31];

int dx[] = { 1,0,-1,0,0,0 };
int dy[] = { 0,1,0,-1,0,0 };
int dh[] = { 0,0,0,0,1,-1 };

queue<tuple<int, int, int>> q;

void bfs(int y, int x, int h) {
	q.push({ y,x,h });
	visited[y][x][h] = true;

	while (!q.empty()) {
		int curr_y = get<0>(q.front());
		int curr_x = get<1>(q.front());
		int curr_h = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int ny = curr_y + dy[i];
			int nx = curr_x + dx[i];
			int nh = curr_h + dh[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C || nh < 0 || nh >= L) continue;

			if (m[ny][nx][nh] != '#'&& !visited[ny][nx][nh]) {
				q.push({ ny,nx,nh });
				visited[ny][nx][nh] = true;
				d[ny][nx][nh] = d[curr_y][curr_x][curr_h] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(;;){
		cin >> L >> R >> C;
		if (C == 0 && R == 0 && C == 0) break;
		for (int h = 0; h < L; h++) {
			for (int i = 0; i < R; i++) {
				string st;
				cin >> st;
				for (int j = 0; j < C; j++) {
					visited[i][j][h] = false;
					d[i][j][h] = 0;
					m[i][j][h] = st[j];

					if (st[j] == 'S') {
						start_y = i;
						start_x = j;
						start_h = h;
					}
					if (st[j] == 'E') {
						end_y = i;
						end_x = j;
						end_h = h;
					}
				}
			}
		}
		bfs(start_y, start_x, start_h);
		if (d[end_y][end_x][end_h] == 0) cout << "Trapped!\n";
		else cout << "Escaped in " << d[end_y][end_x][end_h] << " minute(s).\n";
		while (!q.empty()) q.pop();
	}

	return 0;
 }