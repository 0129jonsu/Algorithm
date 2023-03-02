#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int N, M, K;
int ans;
pair<int, int> map[51][51][8];
int check[51][51];
queue<tuple<int, int, int, int, int>> q;
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        q.push(make_tuple(r, c, m, s, d));
    }

    for (int i = 0; i < K; i++) {
        ans = 0;
        int d_check = 0;
        int size = q.size();
        for (int j = 0; j < size; j++) {
            if (!q.empty()) {
                int curr_x = get<1>(q.front());
                int curr_y = get<0>(q.front());
                int curr_m = get<2>(q.front());
                int curr_s = get<3>(q.front());
                int curr_d = get<4>(q.front());
                q.pop();
                int next_x = curr_x + dx[curr_d] * curr_s;
                int next_y = curr_y + dy[curr_d] * curr_s;


                if (next_x < 1) {
                    next_x = (curr_x + N - curr_s % N);
                    if (next_x > N) next_x -= N;
                }
                else if (next_x > N) next_x = (curr_x + curr_s) % N;
                if (next_x == 0) next_x = N;
                if (next_y < 1) {
                    next_y = (curr_y + N - curr_s % N);
                    if (next_y > N) next_y -= N;
                }
                else if (next_y > N) next_y = (curr_y + curr_s) % N;
                if (next_y == 0) next_y = N;

                map[next_y][next_x][curr_d].first += curr_m;
                map[next_y][next_x][curr_d].second += curr_s;
                check[next_y][next_x]++;
            }
            else {
                cout << 0;
                return 0;
            }
        }
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                if (check[a][b] >= 2) {
                    int s_m = 0, s_s = 0;
                    int odd_check = 0;
                    int even_check = 0;
                    for (int k = 0; k < 8; k++) {
                        if (map[a][b][k].first != 0) {
                            s_m += map[a][b][k].first;
                            s_s += map[a][b][k].second;
                            map[a][b][k] = { 0,0 };
                            if (k % 2 == 0) even_check++;
                            else if (k % 2 != 0) odd_check++;
                        }
                    }
                    s_m = s_m / 5;
                    s_s = s_s / check[a][b];
                    ans += s_m * 4;

                    if (s_m > 0) {
                        if (even_check != 0 && odd_check != 0) {
                            q.push(make_tuple(a, b, s_m, s_s, 1));
                            q.push(make_tuple(a, b, s_m, s_s, 3));
                            q.push(make_tuple(a, b, s_m, s_s, 5));
                            q.push(make_tuple(a, b, s_m, s_s, 7));
                        }
                        else {
                            q.push(make_tuple(a, b, s_m, s_s, 0));
                            q.push(make_tuple(a, b, s_m, s_s, 2));
                            q.push(make_tuple(a, b, s_m, s_s, 4));
                            q.push(make_tuple(a, b, s_m, s_s, 6));
                        }
                    }
                }
                else if (check[a][b] == 1) {
                    for (int k = 0; k < 8; k++) {
                        if (map[a][b][k].first != 0) {
                            q.push(make_tuple(a, b, map[a][b][k].first, map[a][b][k].second, k));
                            ans += map[a][b][k].first;
                            map[a][b][k] = { 0,0 };
                        }
                    }
                }
                check[a][b] = 0;
            }
        }
    } 

    cout << ans;
     
    return 0;
}