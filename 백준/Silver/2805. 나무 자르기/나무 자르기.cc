#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	long long N, M;
	long long l = 0;
	long long h = 0;
	vector<long long> tree;
	long long tmp;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tree.push_back(tmp);
		h = max(h, tmp);
	}

	while (l + 1 < h) {
		long long m = (l + h) / 2;
		
		long long sum = 0;
		for (int i = 0; i < N; i++)
			if (tree[i] > m) sum += tree[i] - m;
		if (sum >= M) l = m;
		else h = m;
	}
	cout << l << "\n";

	return 0;
}