#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{

	if (a.first == b.first) return a.second > b.second;

	return a.first < b.first;
}

int main() {
	pair<int, int> vec[11];
	int pan = 0;
	int t = 0;

	for (int i = 0; i < 11; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec, vec + 11, compare);

	for (int i = 0; i < 11; i++) {
		t += (11-i) * vec[i].first;
		if(vec[i].second != 0) pan += 20 * vec[i].second;
	}

	pan += t;

	cout << pan;

	return 0;
}