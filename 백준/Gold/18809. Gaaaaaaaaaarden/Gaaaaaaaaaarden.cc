#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m, g, r, flower;
int map[51][51];
int col[3];    // green, red, 빈칸
vector<pair<int, int>> v;
queue<tuple<int, int, int>> q;    // x, y, time
void sol(int cnt) {
    if (cnt == v.size()) {
        int ans = 0;
        // bfs    
        int w[51][51];
        int t[51][51];    // 각 지점에 배양액이 도달한 시간
        for (int i = 0; i < n; i++) {
            fill(w[i], w[i] + m, 0);
            fill(t[i], t[i] + m, 0);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                if (map[i][j] == 0) w[i][j] = 1;    // 호수 초기화
        }
        for (auto c : v) {
            if (map[c.first][c.second] == 3 || map[c.first][c.second] == 4) {
                w[c.first][c.second] = map[c.first][c.second];
                q.push({c.first, c.second, 0});
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int x, y, tm;
            tie(x, y, tm) = cur;
            if (w[x][y] == 7) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
                if (w[nx][ny] == 1) continue;    // 호수 
                if (w[nx][ny] == 0) {
                    w[nx][ny] = w[x][y];
                    q.push({nx, ny, tm + 1});
                    t[nx][ny] = tm + 1;
                } else if (w[nx][ny] == 4) {
                    if (w[x][y] == 3 && t[nx][ny] == tm + 1) {
                        ans++;
                        w[nx][ny] = 7;
                    }
                } else if (w[nx][ny] == 3) {
                    if (w[x][y] == 4 && t[nx][ny] == tm + 1) {
                        ans++;
                        w[nx][ny] = 7;
                    }
                }
            }
        }
        flower = max(flower, ans);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (col[i] == 0) continue;
        col[i]--;
        if (i == 0) map[v[cnt].first][v[cnt].second] = 4;    // green
        else if (i == 1) map[v[cnt].first][v[cnt].second] = 3;    // red
        else  map[v[cnt].first][v[cnt].second] = 2;    // 빈칸
        sol(cnt + 1);
        col[i]++;
        map[v[cnt].first][v[cnt].second] = 2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) v.push_back({i, j});
        }
    }
    col[0] = g;
    col[1] = r;
    col[2] = v.size() - g - r;
    sol(0);
    cout << flower;
    return 0;
}