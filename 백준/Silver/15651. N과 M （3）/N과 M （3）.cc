#include <iostream>
using namespace std;

int N, M;
int arr[9];

void f(int num, int cnt){
	if(cnt == M){
		for(int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i = 1; i <= N; i++){
		arr[cnt] = i;
		f(i, cnt+1);
	}
	
}

int main() {
	cin >> N >> M;
	
	f(1,0);
	
	return 0;
}