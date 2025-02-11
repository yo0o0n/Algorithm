#include <iostream>
#include <vector>
using namespace std;

int board[19][19];
int backX, backY;
int dx[] = { 1, 0, 1, -1 };
int dy[] = { 0, 1, 1, 1 };

bool isvalid(int x, int y) {
    return x >= 0 && x < 19 && y >= 0 && y < 19;
}
bool check(int x, int y) {
    if (board[x][y] == 0) return false; // 빈칸 무시
    for (int dir = 0; dir < 4; dir++) {
        int cnt = 1;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // 정방향으로 연속된 돌 확인
        while (isvalid(nx, ny) && board[nx][ny] == board[x][y]) {
            cnt++;
            nx += dx[dir];
            ny += dy[dir];
        }
        // 연속된 돌 앞쪽 칸 확인
        int frontX = nx;
        int frontY = ny;
        // 반대 방향으로 연속된 돌 확인
        nx = x - dx[dir];
        ny = y - dy[dir];
        if (!isvalid(nx, ny) && board[nx][ny] == board[x][y]) {
            cnt++;
            nx -= dx[dir];
            ny -= dy[dir];
        }
        // 연속된 돌 뒤쪽 칸 확인
        backX = nx + dx[dir];
        backY = ny + dy[dir];
        // 5개 연속된 돌 확인
        if (cnt == 5) {
            // 양 끝이 유효하지 않거나 양 끝에 같은 색의 돌이 없는 경우
            if ((!isvalid(frontX, frontY) || board[frontX][frontY] != board[x][y]) &&
                (!isvalid(backX - dx[dir], backY - dy[dir]) || board[backX - dx[dir]][backY- dy[dir]] != board[x][y]))
                return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (check(i, j)) {
                cout << board[i][j] << '\n' << backX + 1 << ' ' << backY + 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << endl; // 승자 X
    return 0;
}