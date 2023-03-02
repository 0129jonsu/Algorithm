#include <iostream>

using namespace std;

int T, N;
string ans;

class Trie {
private:
	Trie* child[11];
	bool finish = false;
	bool exi = false;

public:
	Trie() {
		for (int i = 0; i < 11; i++)
			child[i] = NULL;	
	}
	~Trie() {
		for (int i = 0; i < 11; i++)
			if(child[i] != NULL)
				delete child[i];
	}

	void insert(const char* w) {
		if (*w == '\0') {
			if (exi == true) ans = "NO";
			finish = true;
			return;
		}
		if (finish == true) ans = "NO";

		int next = *w - '0';
		
		exi = true;

		if (child[next] == NULL) child[next] = new Trie();

		return child[next]->insert(w + 1);
	}
};

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		Trie t;
		ans = "YES";
		for (int j = 0; j < N; j++) {
			string st;
			cin >> st;
			t.insert(st.c_str());
		}
		cout << ans << "\n";
	}

	return 0;
}