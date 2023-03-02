#include <iostream>
#include <vector>

using namespace std;

int N, B, C;
long long ans = 0;
vector<int> room;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		room.push_back(tmp);
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		int left = room[i] - B;
		ans++;
		if (left <= 0) continue;
		else {
			ans += (left / C);
			if (left % C != 0) ans++;
		}
	}

	cout << ans;

	return 0;
}