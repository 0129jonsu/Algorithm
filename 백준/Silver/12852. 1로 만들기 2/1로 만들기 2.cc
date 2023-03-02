#include <iostream>

using namespace std;

int N;
int arr[1000001];
int pre[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	arr[1] = 0;

	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 2 == 0 && arr[i / 2] + 1 < arr[i]) {
			arr[i] = arr[i / 2] + 1;
			pre[i] = i / 2;
		}

		if (i % 3 == 0 && arr[i / 3] + 1 < arr[i]) {
			arr[i] = arr[i / 3] + 1;
			pre[i] = i / 3;
		}
	}

	cout << arr[N] << "\n";
	int tmp = N;
	while (tmp != 0) {
		cout << tmp << " ";
		tmp = pre[tmp];
	}

	return 0;
}