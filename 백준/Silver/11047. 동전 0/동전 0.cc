#include <iostream> 
#include <algorithm>

using namespace std;

int main() {
	int N;
	int K;
	int arr[10];
	int idx;
	int ans = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	idx = N-1;
	while (K != 0) {
		if (K >= arr[idx]) {
			K -= arr[idx];
			ans++;
		}
		else {
			idx--;
		}
	}
	
	cout << ans;

	return 0;
}