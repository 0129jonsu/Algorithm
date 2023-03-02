#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	map<string, int> m;
	string st[100001];
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		m.insert({ tmp,i });
		st[i] = tmp;
	}

	for (int j = 0; j < M; j++) {
		string tmp;
		cin >> tmp;
		if (m.find(tmp) != m.end()) {
			cout << m.find(tmp)->second << "\n";
		}
		else {
			cout << st[stoi(tmp)] << "\n";
		}
	}
	return 0;
}