#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool com(long long a, long long b) {
	return a > b;
}

int N;
vector<long long> arr;
int ansl, ansr, ansm;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end(), com);

	long long ans = 3000000001;
	int l, r;
	int ansl, ansr, ansm;

	for (int i = 0; i < N; i++) {

		l = i + 1;
		r = N - 1;
		
		while (l < r) {
			long long anstmp = arr[i] + arr[l] + arr[r];
			
			if (ans > abs(anstmp)) {
				ans = abs(anstmp);
				ansl = i;
				ansm = l;
				ansr = r;
			}

			if (anstmp > 0) l++;
			else r--;
		}
	}

	cout << arr[ansr] << " " << arr[ansm] << " " << arr[ansl];

	return 0;
}