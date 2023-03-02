#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

int ans = 0;
string map = "";
queue<string> q;
set<string> s;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void f(string st) {
	q.push(st);
	while (!q.empty()) {
		if (s.find("123456780") != s.end()) {
			cout << ans;
			return;
		}
		int size = q.size();
		for (int k = 0; k < size; k++) {
			string curr = q.front();
			q.pop();
			int pos = curr.find('0');
			int curr_x = pos % 3;
			int curr_y = pos / 3;
			for (int i = 0; i < 4; i++) {
				int next_x = curr_x + dx[i];
				int next_y = curr_y + dy[i];
				if (next_x < 0 || next_x>2 || next_y < 0 || next_y>2) continue;

				char c = curr[pos];
				curr[pos] = curr[next_x + next_y * 3];
				curr[next_x + next_y * 3] = c;

				if (s.find(curr) == s.end()) {
					q.push(curr);
					s.insert(curr);
				}

				c = curr[pos];
				curr[pos] = curr[next_x + next_y * 3];
				curr[next_x + next_y * 3] = c;
			}
		}
		ans++;
	}
	cout << -1;
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			string tmp;
			cin >> tmp;
			map += tmp;
		}
	}
	s.insert(map);
	f(map);

	return 0;
}