#include <iostream>
#include <algorithm>
#include <deque>


using namespace std;

int main() {
	int N, K;
	int map[101][101];
	deque<pair<int, int>> dq;
	
	int r[4] = { 0,1,0,-1 };
	int c[4] = { 1,0,-1,0 };
	int dir = 0;
	int hr = 0;
	int hc = 0;

	cin >> N >> K;

	map[0][0] = -1;
	for (int i = 0; i < K; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		map[tmp1-1][tmp2-1] = 1;
	}
	int L;
	int cnt = 0;
	cin >> L;
	dq.push_back({ 0,0 });

	for (int i = 0; i < L; i++) {
		int t;
		char h;
		cin >> t >> h;
		while (cnt < t) {
			hr += r[dir];
			hc += c[dir];
			cnt++;

			if (hc >= N || hc < 0 || hr >= N || hr < 0) {
				cout << cnt;
				return 0;
			}

			dq.push_back({ hr,hc });

			if (map[hr][hc] == -1) {
				cout << cnt;
				return 0;
			}
			if (map[hr][hc] == 1) {
				map[hr][hc] = -1;
				continue;
			}

			map[hr][hc] = -1;
			map[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
		}
		if (h == 'D') {
			dir++;
			if (dir == 4) dir = 0;
		}
		if (h == 'L') {
			dir--;
			if (dir == -1) dir = 3;
		}
	}
	while (true) {
		hr += r[dir];
		hc += c[dir];
		cnt++;

		if (hc >= N || hc < 0 || hr >= N || hr < 0) {
			break;
		}
		dq.push_back({ hr,hc });
		if (map[hr][hc] == -1) {
			break;
		}
		if (map[hr][hc] == 1) {
			map[hr][hc] = -1;
			continue;
		}
		map[hr][hc] = -1;
		map[dq.front().first][dq.front().second] = 0;
		dq.pop_front();
	}
	cout << cnt;

	return 0;
}