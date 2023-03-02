#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>v1, pair<int,int>v2) {
	 return v1.second < v2.second;
}

int main() {
	int N;
	int tmp;
	int count = 1;
	pair<int, int>t[100000];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> t[i].first >> t[i].second;
	}
	sort(t, t + N);
	sort(t, t + N, compare);

	tmp = t[0].second;

	for (int i = 1; i < N; i++) {
		
		if (tmp <= t[i].first) {
			tmp = t[i].second;
			count++;
		}
	}
	
	cout << count;

	return 0;
}