#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int pre_m = 0;
int m;
vector<int> v(n);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	int pre = 0;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (i == 0) {
			pre = tmp;
			continue;
		}
		m = abs(pre - tmp);
		if (i == 1 || i == n - 1) {
			v.push_back(m);
			if (i == n - 1) {
				v.push_back(max(m, pre_m));
				break;
			}
		}
		else {
			v.push_back(max(m, pre_m));
		}
		pre_m = m;
		pre = tmp;
	} 

	sort(v.begin(), v.end());

	if (n - k - 1 != -1) cout << v[n - k - 1];
	else cout << 0;

	return 0;
}