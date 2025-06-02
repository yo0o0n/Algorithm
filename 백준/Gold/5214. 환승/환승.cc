#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define MAX 100000

int n, k, m, r;
int dist[MAX + 1000 + 1];
vector<int> st[MAX + 1000 + 1];
queue<int> q;

int bfs() {
	q.push(1);
	dist[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == n) return dist[n]; // 목적지 도착
		for (int i = 0; i < st[cur].size(); i++) {
			int node = st[cur][i]; // cur에서 갈 수 있는 곳
			if (dist[node] == 0) {
				q.push(node);
				if (node > MAX) dist[node] = dist[cur]; // 갈 수 있는 곳이 하이퍼루프
				else dist[node] = dist[cur] + 1; // 갈 수 있는 곳이 역
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= k; j++) {
			cin >> r;
			st[r].push_back(MAX + i);
			st[MAX + i].push_back(r);
		}
	cout << bfs();
	return 0;
}