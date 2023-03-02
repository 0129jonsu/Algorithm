#include <bits/stdc++.h>

using namespace std;

int N;
int m[26][26];
int visited[26][26] = { 0, };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cnt = 0;

vector<int> v;
vector<string> stv;

void dfs(int y, int x) {
	cnt++;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

		if (m[ny][nx] == 1 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;
		stv.push_back(st);
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = int(stv[i][j] - '0');
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && m[i][j] == 1) {
				dfs(i, j);
				if (cnt != 0) {
					v.push_back(cnt);
					cnt = 0;
				}
			}
		}

	}
	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	
	return 0;
}