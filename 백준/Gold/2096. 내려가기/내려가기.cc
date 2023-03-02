#include <bits/stdc++.h>

using namespace std;

int arr[3];
int N;
int dp_max[2][3];
int dp_min[2][3];
int ans_min = 999999;
int ans_max = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		dp_min[1][i] = arr[i];
		dp_max[1][i] = arr[i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}
		dp_min[0][0] = arr[0] + min(dp_min[1][0], dp_min[1][1]);
		dp_max[0][0] = arr[0] + max(dp_max[1][0], dp_max[1][1]);

		dp_min[0][1] = arr[1] + min({ dp_min[1][0], dp_min[1][1], dp_min[1][2] });
		dp_max[0][1] = arr[1] + max({ dp_max[1][0], dp_max[1][1], dp_max[1][2] });

		dp_min[0][2] = arr[2] + min(dp_min[1][1], dp_min[1][2]);
		dp_max[0][2] = arr[2] + max(dp_max[1][1], dp_max[1][2]);

		for (int j = 0; j < 3; j++) {
			dp_min[1][j] = dp_min[0][j];
			dp_max[1][j] = dp_max[0][j];
		}
	}

	ans_min = min({ dp_min[1][0], dp_min[1][1], dp_min[1][2] });
	ans_max = max({ dp_max[1][0], dp_max[1][1], dp_max[1][2] });
	

	cout << ans_max << " " << ans_min << "\n";
	return 0;
}