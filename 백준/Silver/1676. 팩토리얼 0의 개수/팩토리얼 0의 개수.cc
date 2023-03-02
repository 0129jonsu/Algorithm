#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 0;
	cnt += N / 5 + N / 25 + N / 125;

	cout << cnt;
	return 0;
}