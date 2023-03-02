#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int M;
	int idx = 0;

	deque<char> dq;
	vector<pair<char, char>> v;
	string str;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		dq.push_back(str[i]);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		char tmp1;
		char tmp2 = ' ';
		cin >> tmp1;
		if (tmp1 == 'P') cin >> tmp2;
		v.push_back({ tmp1,tmp2 });
	}

	for (int i = 0; i < M; i++) {
		if (v[i].first == 'L' && idx != dq.size()) {
			dq.push_front(dq.back());
			dq.pop_back();
			idx++;

		}
		else if (v[i].first == 'D' && idx != 0) {
			dq.push_back(dq.front());
			dq.pop_front();
			idx--;

		}
		else if (v[i].first == 'B' && idx != dq.size()) {
			dq.pop_back();
		}
		else if (v[i].first == 'P') {
			dq.push_back(v[i].second);
		}
	}

	if (idx > 0) {
		for (int i = 0; i < idx; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
	}
	else if(idx < 0) {
		for (int i = 0; i < abs(idx); i++) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}
	int sz = dq.size();
	for (int i = 0; i < sz; i++) {
		cout << dq.front();
		dq.pop_front();
	}
	 
	return 0;
}