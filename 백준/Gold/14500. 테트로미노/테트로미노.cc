#include<iostream>
using namespace std;
int map[501][501];
int visited[501][501];
int n, m, ans;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x, int d, int sum) {
    sum += map[y][x];
    visited[y][x] = 1;
    if (d == 4) {
        if (sum > ans) ans = sum;
        visited[y][x] = 0;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
            if (!visited[ny][nx])
                dfs(ny, nx, d + 1, sum);
        }
    }
    visited[y][x] = 0;
}

void ex(int y, int x) { // 예외 ㅗ, ㅜ, ㅏ, ㅓ
    int sum;
    for (int i = 0; i < 4; i++) {
        sum = map[y][x];
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;
            int ny = y + dy[j];
            int nx = x + dx[j];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                sum += map[ny][nx];
        }
        if (sum > ans) ans = sum;
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
            
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 1, 0);
            ex(i, j);
        }
    }
    cout << ans;
    return 0;
}