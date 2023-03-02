#include <bits/stdc++.h>

using namespace std;

char pic[101][101];
bool visited[101][101];
int N;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

		if (pic[ny][nx] == pic[y][x] && visited[ny][nx] == 0) dfs(ny, nx);
	}
}

void dfs_RG(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

		if ((pic[y][x] == 'R' || pic[y][x] == 'G') && visited[ny][nx] == 0) {
			if (pic[ny][nx] == 'R' || pic[ny][nx] == 'G') dfs_RG(ny, nx);
		}

		else if (pic[ny][nx] == pic[y][x] && visited[ny][nx] == 0) dfs_RG(ny, nx);
	}
}

int main() {
	cin >> N;
	fill(&visited[0][0], &visited[100][101], false);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> pic[y][x];
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";

	cnt = 0;
	fill(&visited[0][0], &visited[100][101], false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				dfs_RG(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << "\n";



	return 0;
}