#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M, B;
	int t = 1000000000, h = 0;
	int arr[501][501];

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= 256; i++) {
		int block = 0;
		int time = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				block += i - arr[n][m];
				if (i - arr[n][m] > 0) time += 1 * (i - arr[n][m]);
				else if (i - arr[n][m] < 0) time += 2 * (arr[n][m] - i);
			}
		}
		if (block > B) break;
		t = min(t, time);
		if (t == time) h = i;
		
	}
		cout << t << " " << h;

	return 0;
}