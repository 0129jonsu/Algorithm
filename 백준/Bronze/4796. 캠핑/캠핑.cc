#include <iostream>

using namespace std; 

int main() {
	int L=1, P=1, V=1;
	int ans[10000];
	int idx = 0;

	while (L != 0 || P != 0 || V != 0) {
		int tmp = 0;
		cin >> L >> P >> V;
		if (L != 0 && P != 0 && V != 0) {
			while (V > 0 && (L != 0 && P != 0 && V != 0)) {
				if (V >= L) tmp += L;
				else tmp += V;
				V -= P;
			}
			ans[idx] = tmp;
			idx++;
		}
	}

	for (int i = 0; i < idx; i++) {
		cout << "Case " << i + 1 << ": " << ans[i] << endl;
	}

	return 0;
}