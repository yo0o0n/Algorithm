#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, r, d, x, y, m1, m2;
    double Max = 0.0;
    vector<vector<int>> graph(1001);
    queue<tuple<int, int, int>> que;
    bool visit[1001][1001] = { 0, };
    cin >> n >> r >> d >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> m1 >> m2;
        graph[m1].emplace_back(m2);
    }
    que.emplace(x, y, -1);
    visit[x][y] = 1;
    while (!que.empty()) {
        int xx = get<0>(que.front());
        int yy = get<1>(que.front());
        int cnt = get<2>(que.front());
        que.pop();
        for (int i = max(0, xx - r); i <= min(1000, xx + r); ++i) {
            for (auto j : graph[i]) {
                if (sqrt(pow(xx - i, 2) + pow(yy - j, 2)) <= r && !visit[i][j]) {
                    que.emplace(i, j, cnt + 1);
                    Max += d / pow(2, cnt + 1);
                    visit[i][j] = true;
                }
            }
        }
    }
    cout << fixed << setprecision(2);
    if (floor(Max * 100) == floor(Max * 10) * 10) 
        cout << setprecision(1) << Max;
    else
        cout << Max;
    return 0;
}