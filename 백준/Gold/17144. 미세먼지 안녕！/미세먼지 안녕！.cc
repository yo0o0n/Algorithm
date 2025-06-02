#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, t, ans; // 남아있는 미세먼지
int a[50][50];
int p[50][50];
vector<int> clean;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void get() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] <= 0) continue;
			ans += a[i][j];
		}
	}
}

void cleaner(int n) {
	int row = clean[n];
	int idx = 0;
	pair<int, int> now = { row, 1 };
	vector<pair<int, int>> e;
	e.push_back({ row, c - 1 });
	e.push_back({ 0, c - 1 });
	e.push_back({ r - 1, c - 1 });
	e.push_back({ r - 1, 0 });
	e.push_back({ 0, 0 });
	int pre = 0; 
	int tmp = 0;
	while (now.second != 0 || now.first != row) {
		tmp = a[now.first][now.second];
		a[now.first][now.second] = pre;
		pre = tmp;
		for (int i = 0; i < e.size(); i++) {
			if (now == e[i])
				n == 0 ? idx = (idx + 3) % 4 : idx = (idx + 1) % 4;
		}
		now.first += dy[idx];
		now.second += dx[idx];
	}
}

void sol(int time) {
	if (t == time) {
		get(); return;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] <= 0) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dy[k];
				int nc = j + dx[k];
				if (nr < 0 || nr >= r || nc < 0 || nc >= c || a[nr][nc] == -1) continue;
				cnt++;
				p[nr][nc] += a[i][j] / 5;
			}
			p[i][j] -= a[i][j] / 5 * cnt;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] += p[i][j];
			p[i][j] = 0;
		}
	}
		cleaner(0); // 위
		cleaner(1); // 아래
		sol(time + 1);
		return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) { 
			cin >> a[i][j];
			if (a[i][j] == -1)
				clean.push_back(i);
		}
	}
	sol(0);
	cout << ans;
	return 0;
}