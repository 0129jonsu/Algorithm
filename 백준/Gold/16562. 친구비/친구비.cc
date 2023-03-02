#include <iostream>

using namespace std;

int arr[10001];
int cost[10001];
bool check[10001];

int find(int a) {
	if (arr[a] == a) return a;
	return arr[a] = find(arr[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (cost[a] < cost[b]) arr[b] = a;
	else arr[a] = b;
}

int main() {
	int N, M, k;
	cin >> N >> M >> k;

	fill(check, check + 10001, false);

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		arr[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = find(i);
		if (!check[tmp]) {
			check[tmp] = true;
			answer += cost[tmp];
		}
	}

	if (answer > k) cout << "Oh no";
	else cout << answer;

	return 0;
}