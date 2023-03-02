#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	if (s[N - 1] == 'y' || s[N - 1] == 'u'
		|| s[N - 1] == 'i' || s[N - 1] == 'o'
		|| s[N - 1] == 'p' || s[N - 1] == 'h'
		|| s[N - 1] == 'j' || s[N - 1] == 'k'
		|| s[N - 1] == 'l' || s[N - 1] == 'b'
		|| s[N - 1] == 'n' || s[N - 1] == 'm') cout << 0 << "\n";
	else cout << 1 << "\n";
	return 0;
}