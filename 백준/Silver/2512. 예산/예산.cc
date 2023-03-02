#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M;
	vector<int> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	cin >> M;

	sort(arr.begin(), arr.end());

	int s = 0;
	int e = arr[N - 1];
	int res, sum;
	
	while (s <= e) {
		sum = 0;
		int m = (s + e) / 2;

		for (int i = 0; i < N; i++) {
			sum += min(arr[i], m);
 		}

		if (M >= sum) {
			res = m;
			s = m + 1;
		}

		else e = m - 1;
	}

	cout << res;


	return 0;
}