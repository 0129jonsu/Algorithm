#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		string str;
		int x;
		cin >> str;
		if (str == "push") {
			cin >> x;
			q.push(x);
		}
		else if (str == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size") cout << q.size() << "\n";
		else if (str == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (str == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}

	return 0;
}