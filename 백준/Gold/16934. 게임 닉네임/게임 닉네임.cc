#include <iostream>

using namespace std;

int N;
string st;

class Trie {
private:
	Trie* child[26];
	int count = 0;
	bool root;
	bool visited = false;
	bool finish = false;

public:
	Trie(bool r) {
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
		root = r;
	}
	Trie() {
		for (int i = 0; i < 26; i++)
			if (child[i] != NULL) delete child[i];
	}

	void insert(const char* w) {
		if (*w == '\0') {
			count++;
			cout << st;
			if (finish) cout << count << "\n";
			else cout << "\n";
			visited = true;
			finish = true;
			st.clear();
			return;
		}
		if (root || visited) st += *w;
		visited = true;
		int next = *w - 'a';

		if (child[next] == NULL) child[next] = new Trie(false);

		child[next]->insert(w + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	Trie t = Trie(true);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;
		t.insert(st.c_str());
	}

	return 0;
}