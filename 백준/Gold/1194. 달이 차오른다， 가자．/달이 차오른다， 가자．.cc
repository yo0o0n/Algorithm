#include <iostream>
#include <queue>
using namespace std;
char graph[51][51];
bool visited[51][51][1<<6];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int n, m, sx, sy;
void bfs() {
    queue<pair<pair<int, int>, pair<int, int>>>q;
    q.push({{sy, sx}, {0, 0}});
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second.first;
        int key = q.front().second.second;
        if(graph[y][x] == '1') {
            cout << cnt;
            return;
        }
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(graph[ny][nx] == '#') continue;
            if(graph[ny][nx] >= 'A' && graph[ny][nx] <= 'F') { // 문
                int room = graph[ny][nx] - 'A';
                // 문 & 열쇠 대조
                bool check = key & (1 << room);
                if(!check || visited[ny][nx][key]) continue;
                visited[ny][nx][key] = 1;
                q.push({{ny, nx}, {cnt + 1, key}});
            } else if(graph[ny][nx] >= 'a' && graph[ny][nx] <= 'f') { // 열쇠
                // 새로운 열쇠 추가
                int newKey = key | (1 << (graph[ny][nx] -'a'));
                if(visited[ny][nx][newKey]) continue;
                q.push({{ny, nx}, {cnt + 1, newKey}});
                visited[ny][nx][newKey] = 1;
            } else {
                if(visited[ny][nx][key]) continue;
                q.push({{ny, nx}, {cnt + 1, key}});
                visited[ny][nx][key] = 1;
            }
        }
    }
    cout << -1; // 탈출 불가
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == '0') {
                sy = i;
                sx = j;
            }
        }
    }
    bfs();
    return 0;
}