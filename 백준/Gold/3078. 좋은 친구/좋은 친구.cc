#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	queue<int> q[21];


	long long ans = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		while (!q[str.size()].empty() && i - q[str.size()].front() > K) q[str.size()].pop();
		ans += q[str.size()].size();
		q[str.size()].push(i);
	}

	cout << ans;

	return 0;
}