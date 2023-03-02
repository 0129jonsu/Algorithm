#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main() {
	int N;
	long long H_max_HP;
	long long H_cur_HP;
	long long H_base_ATK;
	long long H_cur_ATK;

	vector<tuple<long long, long long, long long>> room;

	cin >> N >> H_base_ATK;
	for (int i = 0; i < N; i++) {
		long long t, a, h;
		cin >> t >> a >> h;
		room.push_back({ t,a,h });
	}
	long long s = 0;
	long long e = 9e18;

	while (s + 1 < e) {
		H_max_HP = (s + e) / 2;
		H_cur_HP = H_max_HP;
		H_cur_ATK = H_base_ATK;

		for (int i = 0; i < N; i++) {
			if (get<0>(room[i]) == 1) { // 몬스터
				while (true) {
					if (get<1>(room[i]) * ((get<2>(room[i]) / H_cur_ATK)-1) < H_cur_HP && get<2>(room[i]) % H_cur_ATK == 0) {
						H_cur_HP -= get<1>(room[i]) * ((get<2>(room[i]) / H_cur_ATK) - 1);
						break;
					}
					else if (get<1>(room[i]) * (get<2>(room[i]) / H_cur_ATK) < H_cur_HP) {
						H_cur_HP -= get<1>(room[i]) * ((get<2>(room[i]) / H_cur_ATK));
						break;
					}
					else {
						s = H_max_HP;
						break;
					}
				}
			}

			else if (get<0>(room[i]) == 2) { // 포션
				H_cur_ATK += get<1>(room[i]);
				H_cur_HP += get<2>(room[i]);
				if (H_cur_HP > H_max_HP) H_cur_HP = H_max_HP;
			}
		}
		if (s != H_max_HP) e = H_max_HP;
	}

	cout << e;

	return 0;
}