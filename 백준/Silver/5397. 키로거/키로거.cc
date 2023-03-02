#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N;
	deque<char> dq;
	deque<char> tmp;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int cnt = 0;
		int sz = str.size();
		for (int j = 0; j < sz; j++) {
			if (str[j] == '<' && !dq.empty()) {
				tmp.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			else if (str[j] == '>' && !tmp.empty()) {
				dq.push_back(tmp.front());
				tmp.pop_front();
				cnt--;
			}
			else if (str[j] == '-' && !dq.empty()) {
				dq.pop_back();
			}

			else if (str[j] != '<' && str[j] != '>' && str[j] != '-') {
				dq.push_back(str[j]);
			}
		}

		if (cnt > 0) {
			for (int x = 0; x < cnt; x++) {
				dq.push_back(tmp.front());
				tmp.pop_front();
			}
		}
			sz = dq.size();
			for (int k = 0; k < sz; k++) {
				cout << dq.front();
				dq.pop_front();

		}
		cout << "\n";
	}

	return 0;
}