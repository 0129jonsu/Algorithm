#include <iostream>

using namespace std;

int map[10][10];
bool c[10][10];
int tmp;
int cnt = 0;

bool check(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if ((n == map[y][i] && x != i) || (n == map[i][x] && y != i)) {
            return true;
        }
    }
    int xx = x / 3 * 3;
    int yy = y / 3 * 3;

    for (int i = yy; i < yy + 3; i++) {
        for (int j = xx; j < xx + 3; j++) {
            if (map[i][j] == n && i != y && j != x) return true;
        }
    }

    return false;
}

void f(int x, int y, int c) {
    if (c == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    if (map[y][x] == 0) {
        for (int k = 1; k <= 9; k++) {
            if (!check(x, y, k)) {
                map[y][x] = k;
                if (x != 8) f(x + 1, y, c + 1);
                else f(0, y + 1, c + 1);
                map[y][x] = 0;
            }
        }
    } 
    else {
        if (x != 8) f(x + 1, y, c);
        else f(0, y + 1, c);
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 9; j++) {
            map[i][j] = tmp[j] - '0';
            if (tmp[j] == '0') cnt++;
        }
    }

    f(0, 0, 81 - cnt);

    return 0;
}