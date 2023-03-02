#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	map<string, string> m;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str1;
		string str2;
		cin >> str1 >> str2;
		m.insert({ str1, str2 });
	}

	for (int i = 0; i < M; i++) {
		string pass;
		cin >> pass;
		cout << m.at(pass) << "\n";
	}

	return 0;
}