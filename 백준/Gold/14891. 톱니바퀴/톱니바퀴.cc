#include <iostream>
#include <cmath>

using namespace std;

char arr[5][9];
bool visited[5];
int K;

void f_1(int);
void f_2(int);

int main() {
	for (int i = 1; i <= 4; i++) {
		string st;
		cin >> st; // 0:N, 1:S  , 12,1,3,5,6,7,9,11시
		for (int j = 0; j < 8; j++) {
			arr[i][j] = st[j];
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int  a, b;
		cin >> a >> b;
		if (b == 1) f_1(a);
		else if (b == -1) f_2(a);

	}

	int ans = 0;
	for (int i = 1; i <= 4; i++) {
		if (arr[i][0] == '1') ans += pow(2, i-1);
	}
	cout << ans;

	return 0;
}

void f_1(int n) {
	visited[n] = true;
	if (n - 1 >= 1 && arr[n][6] != arr[n - 1][2] && !visited[n - 1]) f_2(n - 1);
	if (n + 1 <= 4 && arr[n][2] != arr[n + 1][6] && !visited[n + 1]) f_2(n + 1);
	char tmp[9];
	for (int i = 0; i < 8; i++) {
		if (i == 7) tmp[0] = arr[n][7];
		else tmp[i + 1] = arr[n][i];
	}
	for (int i = 0; i < 8; i++) {
		arr[n][i] = tmp[i];
	}
	visited[n] = false;
}

void f_2(int n) {
	visited[n] = true;
	if (n - 1 >= 1 && arr[n][6] != arr[n - 1][2]&& !visited[n - 1]) f_1(n - 1);
	if (n + 1 <= 4 && arr[n][2] != arr[n + 1][6]&& !visited[n + 1]) f_1(n + 1);
	char tmp[9];
	for (int i = 0; i < 8; i++) {
		if (i == 0) tmp[7] = arr[n][0];
		else tmp[i - 1] = arr[n][i];
	}
	for (int i = 0; i < 8; i++) {
		arr[n][i] = tmp[i];
	}
	visited[n] = false;
}