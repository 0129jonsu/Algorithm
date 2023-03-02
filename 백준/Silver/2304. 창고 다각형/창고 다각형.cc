#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int N;
	int ans = 0;
	vector<pair<int, int>> v;
	stack<pair<int,int>> st;
	bool t = false;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L>> H;
		v.push_back({ L,H });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (st.empty()) st.push({ v[i].first,v[i].second });
		else if (st.top().second <= v[i].second) {
			ans += st.top().second * (v[i].first - st.top().first);
			st.pop();
			st.push({ v[i].first,v[i].second });
		}
	}
	ans += st.top().second;
	st.pop();
	for (int i = N - 1; i >= 0; i--) {
		if (st.empty()) st.push({ v[i].first,v[i].second });
		else if (st.top().second < v[i].second) {
			ans += st.top().second * (st.top().first - v[i].first);
			st.pop();
			st.push({ v[i].first,v[i].second });
		}
	}
	cout << ans;

	return 0;
}