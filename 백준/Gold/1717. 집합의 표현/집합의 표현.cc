#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> v1;

int find(int p) {
	if (v1[p] < 0) return p;
	return v1[p] = find(v1[p]);
}

void merge(int p, int q) {
	p = find(p);
	q = find(q);
	if (p == q) return;
	v1[q] = p;
}

void check(int p, int q) {
	p = find(p);
	q = find(q);
	if (p == q) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	v1.resize(n+1);
	fill(v1.begin(), v1.end(), -1);

	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c) check(a, b);
		else merge(a, b);
	}

	return 0;
}