#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int N, M;
int cnt = 0;
int cnt_chicken = 0;
int cnt_house = 0;
int comp[101];
bool visited[14];
int ans = 1000000000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> sel;

void select_chicken(int cnt, int idx) {
    if (cnt == M) {
        for (int i = 0; i < cnt_house; i++) {
            comp[i] = 1000000000;
        }
        for (int i = 0; i < M; i++) {
            int tmpans = 0;
            for (int j = 0; j < cnt_house; j++) {
                int a = abs(sel[i].first - house[j].first) + abs(sel[i].second - house[j].second);
                comp[j] = min(comp[j], a);
            }
        }
        int tmpans = 0;
        for (int i = 0; i < cnt_house; i++) {
            tmpans += comp[i];
        }
        ans = min(ans, tmpans);
        return;
    }

    for (int i = idx; i < cnt_chicken; i++) {
        if (!visited[idx]) {
            visited[idx] = true;
            sel.push_back(chicken[i]);
            select_chicken(cnt + 1, i + 1);
            sel.pop_back();
            visited[idx] = false;
        }
    }
}

int main() {
    cin >> N >> M;
 

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) house.push_back({ i,j });
            else if (tmp == 2) chicken.push_back({ i,j });
        }
    }
    cnt_chicken = chicken.size();
    cnt_house = house.size();

    select_chicken(0, 0);

    cout << ans;

    return 0;
}