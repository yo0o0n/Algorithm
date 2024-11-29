#include<iostream>
using namespace std;

int n, m;
int map[1001][1001];
int dp[1001][1001];
int R[1001];
int L[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	dp[0][0] = map[0][0];
	for (int j = 1; j < m; j++)		// 맨 윗줄 dp 생성
		dp[0][j] += dp[0][j - 1] + map[0][j];
	for (int i = 1; i < n; i++) {
		R[0] = dp[i - 1][0] + map[i][0];	// L -> R
		for (int j = 0; j < m - 1; j++)
			R[j + 1] = max(R[j], dp[i - 1][j + 1]) + map[i][j + 1];
		L[m - 1] = dp[i - 1][m - 1] + map[i][m - 1];	// R -> L
		for (int j = m - 2; j >= 0; j--)
			L[j] = max(L[j + 1], dp[i - 1][j]) + map[i][j];
		for (int k = 0; k < m; k++)
			dp[i][k] = max(R[k], L[k]);
	}
	cout << dp[n - 1][m - 1];
	return 0;
}