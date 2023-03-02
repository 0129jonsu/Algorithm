#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int N;
int L;
int ans = 0;
int tmp;
int arr[1000];

int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+N);

	for (int i = 0; i < N;) {
		if (arr[i] != NULL && arr[i + 1] == NULL) {
			ans++;
			break;		
		}
		else if (abs(arr[i] - arr[i+1]) < L) {
			int j = i + 1;
			while (abs(arr[i] - arr[j]) < L) {
				j++;
			}
			ans++;
			i = j;
		}
		else if (abs(arr[i] - arr[i+1]) >= L) {
			ans++;
			i++;
		}
	}

	cout << ans;

	return 0;
}