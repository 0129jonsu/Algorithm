#include <iostream>
#include <unordered_map>

using namespace std;

int arr[200002];
unordered_map<string, int> um;
int m[200002];

int find(int a) {
	if (arr[a] < 0) return a;
	return find(arr[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	m[a] += m[b];
	arr[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		fill(m, m + 200002, 1);
		fill(arr, arr + 200002, -1);
		int idx = 1;
		um.clear();
		int F;
		cin >> F;

		
		for (int j = 1; j <= F; j++) {
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			if (um[tmp1] == 0) {
				um[tmp1] = idx;
				idx++;
			}
			if (um[tmp2] == 0) {
				um[tmp2] = idx;
				idx++;
			}
			merge(um[tmp1], um[tmp2]);
			cout << m[find(um[tmp1])] << "\n";
		}
	}

	return 0;
}