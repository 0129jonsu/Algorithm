#include <iostream>

using namespace std;

int N, M;
int arr[201];

int find(int n) {
	if (arr[n] == n) return n;
	return arr[n] = find(arr[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	arr[b] = a;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		arr[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int s;
			cin >> s;
			if (s) merge(i, j);
		}
	}
	int p;
	cin >> p;
	int tmp = find(p);
	for (int i = 2; i <= M; i++) {
		cin >> p;
		if (tmp != find(p)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}