#include <iostream>
#include <queue>

using namespace std;

int N, L, R;
int map[51][51];
bool visited[51][51];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool check = false;
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int cnt = -1;
int sum = 0;

void f() {
	sum = 0;
	while (!q1.empty()) {
		int curr_x = q1.front().first;
		int curr_y = q1.front().second;
		q1.pop();
		sum += map[curr_y][curr_x];

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
			int c = abs(map[curr_y][curr_x] - map[next_y][next_x]);
			if (!visited[next_y][next_x] && L <= c && c <= R) {
				check = false;
				visited[next_y][next_x] = true;
				q1.push({ next_x,next_y });
				q2.push({ next_x,next_y });
			}
		}
	}

}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	while (!check) {
		fill(&visited[0][0], &visited[50][51], false);
		check = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					q1.push({ j,i });
					q2.push({ j,i });
					visited[i][j] = true;
					f();
					sum /= q2.size();
					while (!q2.empty()) {
						map[q2.front().second][q2.front().first] = sum;
						q2.pop();
					}
				}
				
			}
		}
		cnt++;
	}

	cout << cnt;

	return 0;
}