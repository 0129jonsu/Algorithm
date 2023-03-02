#include <iostream>

using namespace std;

int N, M, K;
int aa[101][101];
int cnt = 0;
int ans = 0;
bool visited[101][101];


int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int vx, int vy) {
	visited[vx][vy] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int xx = vx + dx[i];
		int yy = vy + dy[i];

		if(xx < 1 || xx > M || yy < 1 || yy > N) continue;

		if (aa[xx][yy] == 1 && !visited[xx][yy]) {
			dfs(xx, yy);
		}
	}
	
}

int main() {
	fill(&aa[0][0], &aa[100][101], 0);
	fill(&visited[0][0], &visited[100][101], 0);

	cin >> N >> M >> K;
	int n, m;
	
	for (int i = 0; i < K; i++) {
		cin >> m >> n;
		aa[n][m] = 1;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && aa[i][j] == 1) {
				cnt = 0;
				dfs(i, j);
				ans = max(ans, cnt);
			}
		}
	}

	cout << ans << endl;
	return 0;
}