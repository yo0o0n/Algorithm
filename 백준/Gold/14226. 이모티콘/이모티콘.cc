#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int S, res = 99999;
int visited[1001][1001];

void bfs() {
	memset(visited, -1, sizeof(visited));
	visited[1][0] = 0;
	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	while (!q.empty()) {
		int i = q.front().first;
		int board = q.front().second;
		int time = visited[i][board];
		q.pop();
		if (i == S) {
			res = min(res, time); continue;
		}
		// 1. 
		if (visited[i][i] == -1) {
			visited[i][i] = time + 1;
			q.push({ i, i });
		}
		// 2. 
		if (i + board <= S && visited[i + board][board] == -1) {
			q.push({ i + board, board });
			visited[i + board][board] = time + 1;
		}
		// 3.
		if (i - 1 >= 0 && visited[i - 1][board] == -1) {
			visited[i - 1][board] = time + 1;
			q.push({ i - 1, board });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> S;
	bfs();
	cout << res;

	return 0;
}