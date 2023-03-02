#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string sentence, char Separator)
{
	vector<string> answer;
	stringstream ss(sentence);
	string tmp;

	while (getline(ss, tmp, Separator)) {
		answer.push_back(tmp);
	}
	return answer;
}

int main() {
	int T;
	int n;
	deque<string> dq;
	string F, N;
	
	cin >> T;

	for (int a = 0; a < T; a++) {
		cin >> F >> n >> N;
		int sz = F.size();

		int idx = 0;
		bool em = true;
		N[0] = ',';
		N[N.size() - 1] = ',';
		vector<string> v = split(N, ',');

		for (int i = 1; i <= n; i ++) {
			dq.push_back(v[i]);
		}
		for (int i = 0; i < sz; i++) {
			if (F[i] == 'R') idx++;
			if (F[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					em = false;
					break;
				}
				else {
					if (idx % 2 == 0) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (!dq.empty() || em) {
			cout << "[";
			sz = dq.size();
			for (int i = 0; i < sz; i++) {
				if (idx % 2 == 0) {
					cout << dq.front();
					if (i == sz - 1);
					else cout << ",";
					dq.pop_front();
				}
				else {
					cout << dq.back();
					if (i == sz - 1);
					else cout << ",";
					dq.pop_back();
				}
			}
			cout << "]\n";
		}

	}


	return 0;
}