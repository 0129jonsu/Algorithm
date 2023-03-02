#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	stack<char> st;
	string str;
	cin >> str;
	int sz = str.size();

	for (int idx = 0; idx < sz; idx++) {
		if (str[idx] == '(') {
			st.push(str[idx]);
		}
		else if (str[idx] == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[idx] == '+' || str[idx] == '-') {	
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
			}
			st.push(str[idx]);
		}
		else if (str[idx] == '*' || str[idx] == '/') {
			if (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(str[idx]);
		}
		else {
			cout << str[idx];
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}