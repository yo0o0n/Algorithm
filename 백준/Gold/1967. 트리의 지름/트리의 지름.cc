#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxNode = 0;
int maxVal = -1;
vector<int> v;
vector<pair<int, int>> node[10001];
void dfs(int now, int val) {
	v[now] = 1;
	if (maxVal < val) {
		maxVal = val;
		maxNode = now;
	}
	for (int i = 0; i < node[now].size(); i++) {	// 현재 지점에서 갈 수 있는 노드
		if (v[node[now][i].first] == 1)	continue;
		dfs(node[now][i].first, val + node[now][i].second);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    v.resize(n + 1, 0);
    int s, e, w;
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> e >> w; // 출발, 도착, 가중치
        node[s].push_back(make_pair(e, w));
        node[e].push_back(make_pair(s, w));
    }
    dfs(1, 0);  // 루트에서 가장 먼 노드
    v.assign(n + 1, 0);
    maxVal = -1;
    dfs(maxNode, 0);
    cout << maxVal << endl;
	return 0;
}