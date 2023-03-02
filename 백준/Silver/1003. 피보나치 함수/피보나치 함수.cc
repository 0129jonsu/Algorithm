#include <iostream>
#include <algorithm>

using namespace std;

int dp[41];

int fibonacci(int n) {
    if (n == 0) {
        dp[0] = 0;
        return 0;
    }
    else if (n == 1) {
        dp[1] = 1;
        return 1;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    else {
        return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int test;
        cin >> test;
        if (test == 0) {
            cout << 1 << " " << 0 << "\n";
        }
        else if (test == 1) {
            cout << 0 << " " << 1 << "\n";
        }
        else {
            fibonacci(test);
            cout << dp[test - 1] << " " << dp[test] << "\n";
        }
    }
    
    return 0;
}