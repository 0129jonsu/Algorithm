#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[101][101];


int main() {
	cin >> n >> m;
	fill(&map[0][0], &map[100][100], 100000000);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][i] + map[i][k] < map[j][k])   map[j][k] = map[j][i] + map[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 100000000 || i==j) cout << 0 << " ";
			else cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}