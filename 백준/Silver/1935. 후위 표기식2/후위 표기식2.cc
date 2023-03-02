#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;

int main() {
	int N;
	stack<double> st;
	string str;
	double arr[27];
	cin >> N;
	cin >> str;
	int sz = str.size();
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < sz; i++) {
		if (str[i] == '+') {
			double tmp1, tmp2;
			tmp2 = st.top();
			st.pop();
			tmp1 = st.top();
			st.pop();
			st.push(tmp1 + tmp2);
		}
		else if (str[i] == '-') {
			double tmp1, tmp2;
			tmp2 = st.top();
			st.pop();
			tmp1 = st.top();
			st.pop();
			st.push(tmp1 - tmp2);
		}
		else if (str[i] == '*') {
			double tmp1, tmp2;
			tmp2 = st.top();
			st.pop();
			tmp1 = st.top();
			st.pop();
			st.push(tmp1 * tmp2);
		}
		else if (str[i] == '/') {
			double tmp1, tmp2;
			tmp2 = st.top();
			st.pop();
			tmp1 = st.top();
			st.pop();
			st.push(tmp1 / tmp2);
		}
		else {
			st.push(arr[str[i] - 'A']);
		}
	}

	cout << st.top();

	return 0;
}