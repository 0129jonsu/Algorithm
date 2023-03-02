#include <iostream>
#include <string>

using namespace std;

int A, B, N, M;
pair<int,int> map[101][101];
pair<int,int> arr[101];
int r_1, r_2;
string ans = "";

int main() {
	cin >> A >> B >> N >> M;
	for (int i = 1; i <= N; i++) {
		int rx, ry;
		char news;
		cin >> rx >> ry >> news;
		map[ry][rx].first = i;
		arr[i].first = rx;
		arr[i].second = ry;
		if(news == 'E') map[ry][rx].second = 1;
		else if(news == 'S') map[ry][rx].second = 2;
		else if(news == 'W') map[ry][rx].second = 3;
		else if(news == 'N') map[ry][rx].second = 4;
	}

	bool check = false;

	for (int i = 1; i <= M; i++) {
		int a, c;
		char b;
		cin >> a >> b >> c;
		int tmp_x = arr[a].first;
		int tmp_y = arr[a].second;
		int r_news = map[tmp_y][tmp_x].second;
		r_1 = a;
		if (b == 'F') map[tmp_y][tmp_x] = { 0,0 };
		for (int k = 1; k <= c; k++) {
			if (b == 'F') {
				if (r_news == 1) tmp_x++;
				else if (r_news == 2) tmp_y--;
				else if (r_news == 3) tmp_x--;
				else if (r_news == 4) tmp_y++;
				if ((tmp_x < 1 || tmp_y < 1 || tmp_x > A || tmp_y > B) && !check) {
					check = true;
					ans += "Robot " + to_string(r_1) + " crashes into the wall";
					break;
				}
				if (map[tmp_y][tmp_x].first != 0 && !check) {
					r_2 = map[tmp_y][tmp_x].first;
					check = true;
					ans += "Robot " + to_string(r_1) + " crashes into robot " + to_string(r_2);
					break;
				}
			}
			else if (b == 'R') {
				map[tmp_y][tmp_x].second++;
				if (map[tmp_y][tmp_x].second == 5) map[tmp_y][tmp_x].second = 1;
			}
			else if (b == 'L') {
				map[tmp_y][tmp_x].second--;
				if (map[tmp_y][tmp_x].second == 0) map[tmp_y][tmp_x].second = 4;
			}
		}
		if (b == 'F') {
			map[tmp_y][tmp_x] = { r_1,r_news };
			arr[a] = { tmp_x,tmp_y };
		}
	} 

	if (check) cout << ans;
	else cout << "OK";


	return 0;
}