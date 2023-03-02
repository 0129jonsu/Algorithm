#include <iostream>

using namespace std;

int N;
string tmp;
char map[6][20001];
string ans = "";

int check(int n) {
    if (n >= N / 5-2) {
        ans += '1';
        return n + 3;
    }
    string st = "";
    string c_1 = "";

    for (int i = 0; i < 5; i++) {
        for (int j = n; j < n + 3; j++) {
            st += map[i][j];
            if (j != n + 3 - 1) c_1 += map[i][j];
        }
    }
    if (c_1 == "#.#.#.#.#.") ans += '1';
    else if (st == "####.##.##.####") ans += '0';
    else if (st == "#..#..#..#..#.." || st == ".#..#..#..#..#." || st == "..#..#..#..#..#") ans += '1';
    else if (st == "###..#####..###") ans += '2';
    else if (st == "###..####..####") ans += '3';
    else if (st == "#.##.####..#..#") ans += '4';
    else if (st == "####..###..####") ans += '5';
    else if (st == "####..####.####") ans += '6';
    else if (st == "###..#..#..#..#") ans += '7';
    else if (st == "####.#####.####") ans += '8';
    else if (st == "####.####..####") ans += '9';
    else if (st == "#.##.##.##.##.#") ans += "11";
    int idx;
    if (st == "#..#..#..#..#.." || c_1 == "#.#.#.#.#.") idx = 1;
    else idx = 3;
    while (map[0][n+idx] != '#') idx++;
    return n + idx;
}

int main() {
    cin >> N;
    cin >> tmp;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N / 5; j++) {
            map[i][j] = tmp[i * (N / 5) + j];
        }
    }
    int a = 0;
    while (1) {
        a = check(a);
        if (a > N / 5) break;
    }

    cout << ans;

    return 0;
}