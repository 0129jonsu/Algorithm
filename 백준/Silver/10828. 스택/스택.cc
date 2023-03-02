#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<int> st;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int tmp;
			cin >> tmp;
			st.push_back(tmp);
		}
		else if (str == "top") {
			if (st.empty()) cout << "-1" << "\n";
			else {
				cout << st.back() << "\n";
				if (st.empty()) cout << "-1" << "\n";
			}
		}
		else if (str == "size") {
			cout << st.size() << "\n";
		}
		else if (str == "empty") {
			if (st.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (str == "pop") {
			if (st.empty()) cout << "-1" << "\n";
			else {
				cout << st.back() << "\n";
				st.pop_back();
			}
		}
	}

	return 0;
}