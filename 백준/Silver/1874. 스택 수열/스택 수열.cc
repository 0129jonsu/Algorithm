#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n;
	int a = 1;
	int arr[100001];
	string str;
	stack<int> st;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int tmp = arr[i];
		if (tmp > a - 1) {
			while (a - 1 != tmp) {
				st.push(a);
				a++;
				str += '+';
			}
		}
		if (tmp <= a && !st.empty()) {
			if (st.top() != tmp) {
				cout << "NO";
				return 0;
			}
			else {
				st.pop();
				str += '-';
			}
		}
	}
	int sz = str.size();
	for (int i = 0; i < sz; i++) {
		cout << str[i] << "\n";
	}

	return 0;
}