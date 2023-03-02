#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, L, R;
int hx, hy;
int f_x, f_y;
int cnt = 1;
int map[1001][1001];
bool visited[1001][1001];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<tuple<int, int, int, int>> q;

void f() {
	while (!q.empty()) {
		int curr_x = get<0>(q.front());
		int curr_y = get<1>(q.front());
		int curr_l = get<2>(q.front());
		int curr_r = get<3>(q.front());
		visited[curr_y][curr_x] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
 			int c = 1;
			if (i == 0 || i == 1) {
				while (1) {
					int next_x = curr_x;
					int next_y = curr_y + dy[i] * c;
					int next_l = curr_l;
					int next_r = curr_r;
					c++;
					if (next_y < 0 || next_y >= N || map[next_y][next_x] == 1) break;
					if (!visited[next_y][next_x] && map[next_y][next_x] == 0) {
						q.push(make_tuple(next_x, next_y, next_l, next_r));
						visited[next_y][next_x] = true;
						cnt++;
					}
				}
			}
			else {
				int next_x = curr_x + dx[i];
				int next_y = curr_y;
				int next_l = curr_l;
				int next_r = curr_r;
				if (i == 3) next_l = curr_l - 1;
				if (i == 2) next_r = curr_r - 1;

				if (next_x < 0 || next_x >= M || next_l < 0 || next_r < 0 || map[next_y][next_x] == 1) continue;
				if (!visited[next_y][next_x] && map[next_y][next_x] == 0) {
					q.push(make_tuple(next_x, next_y, next_l, next_r));
					visited[next_y][next_x] = true;
					cnt++;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> L >> R;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			map[i][j] = tmp[j] - '0';
			if (map[i][j] == 2) {
				f_x = j;
				f_y = i;
				q.push(make_tuple(j, i, L, R));
			}
		}
	}

	f();

	cout << cnt;

	return 0;
}