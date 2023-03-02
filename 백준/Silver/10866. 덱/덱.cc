#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N;
	deque<int> dq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		string str;
		cin >> str;
		if (str == "push_front") {
			cin >> tmp;
			dq.push_front(tmp);
		}
		else if (str == "push_back") {
			cin >> tmp;
			dq.push_back(tmp);
		}
		else if (str == "pop_front") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "front") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << "\n";
		}
		else if (str == "back") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << "\n";
		}
	}

	return 0;
}