#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Trie {
private:
	Trie* child[26];
	int child_c;
	bool finish = false;
	bool root = false;

public:
	Trie(bool r) {
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
		child_c = 0;
		root = r;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) 
			if (child[i] != NULL) delete child[i];
	}

	void insert(const char* w) {
		if (*w == '\0') {
			finish = true;
			return;
		}

		int next = *w - 'a';

		if (child[next] == NULL) {
			child[next] = new Trie(false);
			child_c++;
		}

		child[next]->insert(w + 1);
	}
	
	int find(const char* w, int n) {
		if (*w == '\0') return n;

		int next = *w - 'a';

		if (child_c > 1 || finish || root) return child[next]->find(w + 1, n + 1);
		else return child[next]->find(w + 1, n);
	}
};

int N;
vector<string> v;

int main() {
	while (cin >> N) {
		Trie t = Trie(true);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			string st;
			cin >> st;
			v.push_back(st);
			t.insert(st.c_str());
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			ans += t.find(v[i].c_str(), 0);
		}
		v.clear();


		cout << setprecision(2) << fixed << double(ans) / N << "\n";
	}

	return 0;
}