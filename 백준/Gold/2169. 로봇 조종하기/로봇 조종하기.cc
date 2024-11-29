#include<iostream>
using namespace std;
int N, M;
int map[1001][1001];
int dp[1001][1001];
int Right[1001];
int Left[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = map[0][0];
	for (int j = 1; j < M; j++) // 맨 윗줄 dp 생성
		dp[0][j] += dp[0][j - 1] + map[0][j];

	for (int i = 1; i < N; i++)
	{
		// 왼쪽 -> 오른쪽
		Right[0] = dp[i - 1][0] + map[i][0];
		for (int j = 0; j < M - 1; j++)
			Right[j + 1] = max(Right[j], dp[i - 1][j + 1]) + map[i][j + 1];

		// 오른쪽 -> 왼쪽
		Left[M - 1] = dp[i - 1][M - 1] + map[i][M - 1];
		for (int j = M - 2; j >= 0; j--)
			Left[j] = max(Left[j + 1], dp[i - 1][j]) + map[i][j];

		for (int k = 0; k < M; k++)
			dp[i][k] = max(Right[k], Left[k]);
	}
	cout << dp[N - 1][M - 1];
	return 0;
}