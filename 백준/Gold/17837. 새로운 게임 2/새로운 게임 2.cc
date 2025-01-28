#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct info {
	int y, x, dir;
};
int K, N;
int arr[14][14];
info tmp;
vector<int> chess[14][14];	// 말 저장 +2 테두리 감싸기
vector<info> v[11];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void start() {
	int cnt = 1;
	bool fini = false;
	while (1) {
		if (cnt > 1000) {
			cout << -1;
			break;
		}
		for (int i = 1; i <= K; i++) {
			int cy = v[i][0].y;
			int cx = v[i][0].x;
			int cd = v[i][0].dir;
			vector<int> vec;
			if (chess[cy][cx].size() > 0) {
				bool find = false;
				for (int j = 0; j < chess[cy][cx].size(); j++) {
					if (!find) {
						if (chess[cy][cx][j] == i) {
							find = true;
							vec.push_back(chess[cy][cx][j]);
						}
					}
					else
						vec.push_back(chess[cy][cx][j]);
				}
			}
			int ny = cy + dy[cd];
			int nx = cx + dx[cd];
			int color = arr[ny][nx];

			if (color == 2) {	// 파란색
				int nd;
				if (cd == 1) nd = 2;
				else if (cd == 2) nd = 1;
				else if (cd == 3) nd = 4;
				else if (cd == 4) nd = 3;
				ny = cy + dy[nd];
				nx = cx + dx[nd];
				v[i][0].dir = nd;

				if (arr[ny][nx] == 2) continue;	// 파란색 or 벽
				else color = arr[ny][nx];
			}
			for (int p = 0; p < vec.size(); p++)	// 기존 말 pop
				chess[cy][cx].pop_back();

			if (color == 1)	// 빨간색
				reverse(vec.begin(), vec.end());
			for (int p = 0; p < vec.size(); p++) {
				int cdx = vec[p];
				chess[ny][nx].push_back(cdx);
				v[cdx][0].y = ny;
				v[cdx][0].x = nx;
			}
			if (chess[ny][nx].size() > 3) {
				fini = true;
				break;
			}
		}
		if (fini) break;
		cnt++;
	}
	if (fini)
		cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N + 2; i++)
		for (int j = 0; j < N + 2; j++)
			arr[i][j] = 2;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	int y, x, d;
	for (int i = 1; i <= K; i++) {
		cin >> y >> x >> d;
		tmp.dir = d;
		tmp.y = y;
		tmp.x = x;
		v[i].push_back(tmp);
		chess[y][x].push_back(i);
	}
	start();
	return 0;
}