#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans = 0;
int arr[501][501];

int s1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {
			int tmp = 0;
			for (int x = 0; x <= 3; x++) {
				tmp += arr[i][j + x];
			}
			ans = max(ans, tmp);
		}
	}

	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			for (int x = 0; x <= 3; x++) {
				tmp += arr[i+x][j];
			}
			ans = max(ans, tmp);
		}
	}
	return ans;
}

int s2() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int tmp = 0;
			for (int y = 0; y <= 1; y++) {
				for (int x = 0; x <= 1; x++) {
					tmp += arr[i + y][j + x];
				}
			}
			ans = max(ans, tmp);
		}
	}
	return ans;
}

int s3() {
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			int tmp_2 = 0;
			for (int y = 0; y <= 2; y++) {
				tmp += arr[i + y][j];
			}
			if (j != M - 1) tmp_2 = max(arr[i][j + 1], arr[i + 2][j + 1]);
			if (j != 0) {
				tmp_2 = max(tmp_2 , arr[i + 2][j - 1]);
				tmp_2 = max(tmp_2, arr[i][j - 1]);
			}
			tmp += tmp_2;
			ans = max(ans, tmp);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			int tmp = 0;
			int tmp_2 = 0;
			for (int x = 0; x <= 2; x++) {
				tmp += arr[i][j + x];
			}
			if (i != N - 1) tmp_2 = max(arr[i + 1][j], arr[i + 1][j + 2]);
			if (i != 0) {
				tmp_2 = max(tmp_2, arr[i - 1][j + 2]);
				tmp_2 = max(tmp_2, arr[i - 1][j]);
			}
			tmp += tmp_2;
			ans = max(ans, tmp);
		}
	}

	return ans;
}

int s4() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			int tmp_2 = 0;
			for (int y = 0; y <= 1; y++) {
				tmp += arr[i + y][j];
			}
			if (i < N - 2) {
				if (j != M - 1) tmp_2 = max(tmp_2, arr[i + 1][j + 1] + arr[i + 2][j + 1]);
				if (j != 0) tmp_2 = max(tmp_2, arr[i + 1][j - 1] + arr[i + 2][j - 1]);
			}
			if (i > 0) {
				if (j != M - 1) tmp_2 = max(tmp_2, arr[i][j + 1] + arr[i - 1][j + 1]);
				if (j != 0) tmp_2 = max(tmp_2, arr[i][j - 1] + arr[i - 1][j - 1]);
			}
			tmp += tmp_2;
			ans = max(ans, tmp);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			int tmp = 0;
			int tmp_2 = 0;
			for (int x = 0; x <= 1; x++) {
				tmp += arr[i][j + x];
			}
			if (j < M - 2) {
				if (i != N - 1) tmp_2 = max(tmp_2, arr[i + 1][j + 1] + arr[i + 1][j + 2]);
				if (i != 0) tmp_2 = max(tmp_2, arr[i - 1][j + 1] + arr[i - 1][j + 2]);
			}
			if (j > 0) {
				if (i != N - 1) tmp_2 = max(tmp_2, arr[i + 1][j] + arr[i + 1][j - 1]);
				if (i != 0) tmp_2 = max(tmp_2, arr[i - 1][j] + arr[i - 1][j - 1]);
			}
			tmp += tmp_2;
			ans = max(ans, tmp);
		}
	}
	return ans;
}

int s5() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			int tmp = 0;
			int tmp_2 = 0;
			for (int x = 0; x <= 2; x++) {
				tmp += arr[i][j + x];
			}
			if (i != 0) tmp_2 = max(tmp_2, arr[i - 1][j + 1]);
			if (i != N - 1) tmp_2 = max(tmp_2, arr[i + 1][j + 1]);
			tmp += tmp_2;
			ans = max(ans, tmp);
		}
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			int tmp_2 = 0;
			for (int y = 0; y <= 2; y++) {
				tmp += arr[i + y][j];
			}
			if (j != 0) tmp_2 = max(tmp_2, arr[i + 1][j - 1]);
			if (j != M - 1) tmp_2 = max(tmp_2, arr[i + 1][j + 1]);
			tmp += tmp_2;
			ans = max(ans, tmp);
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >>arr[i][j];
		}
	}

	s1();
	s2();
	s3();
	s4();
	s5();

	cout << ans;

	return 0;
}