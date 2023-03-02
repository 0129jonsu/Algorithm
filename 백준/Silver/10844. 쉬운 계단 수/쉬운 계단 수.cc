#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long a;
long long dp[101][10];
long long mod = 1000000000;

long long f(long long n, long long k) {
	if (n == 1) { // 한자리 수 일때
		if (k == 0) return 0; // 0이면 reurn 0
		else return 1; // 1~9면 return 1
	}

	if (dp[n][k] != -1) return dp[n][k]; // 이미 계산한 값이면 return

	if (k == 0) dp[n][k] = f(n - 1, 1) % mod; // 끝자리 0일 때 예외
	else if (k == 9) dp[n][k] = f(n - 1, 8) % mod; // 끝자리 9일 때 예외
	else dp[n][k] = (f(n - 1, k - 1) + f(n - 1, k + 1)) % mod; // 나머지 계산

	return dp[n][k];

}

int main() {
	fill(&dp[0][0], &dp[100][10], -1);
	cin >> N;

	for (long long i = 0; i < 10; i++) {
		a = (a + f(N, i)) % mod;
	}
	
	cout << a;

	return 0;
}