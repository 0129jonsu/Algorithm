#include <iostream>
using namespace std;
int N,M,a=0;
int m[501][501];
int main() {
	cin >> N >> M;
	for(int i=0;i<M;i++){int a, b;cin >> a >> b;m[b][a] = 1;}
	for(int i=1;i<=N;i++){for(int j=1;j<=N;j++){for(int k=1;k<=N;k++) {if (m[j][i]+m[i][k]==2)m[j][k]=1;if (m[j][k]==1)m[k][j]=-1;}}}
	for (int i=1;i<=N;i++){int t=0;
	for (int j=1;j<=N;j++){if(m[i][j]||m[i][j]==-1)t++;}if(t==N-1)a++;}
	cout << a;
}