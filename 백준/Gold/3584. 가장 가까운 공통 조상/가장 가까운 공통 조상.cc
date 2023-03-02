#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<int> v1;
int graph[10002];
bool visited[10002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			graph[i] = i;
			visited[i] = false;
		}
		
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			graph[b] = a;
		}
		int s1, s2;
		cin >> s1 >> s2;
		visited[s1] = true;
		do {
			s1 = graph[s1];
			visited[s1] = true;
		} while (s1 != graph[s1]);

		do {
			s2 = graph[s2];
			if (visited[s2]) cout << s2 << "\n";
		} while (!visited[s2]);


	}

	return 0;
}