#include<iostream>
#include<algorithm>
using namespace std;

int T, W;
int A[1001];
int dp[1001][32][3];
int ans = 0;

void sol() {
	dp[1][0][1] = A[1] == 1;
	dp[1][1][2] = A[1] == 2;
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + (A[i] == 1);
			dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + (A[i] == 2);
		}
	}
	for (int i = 0; i <= W; i++) {
		for (int j = 1; j <= 2; j++) 
			ans = max(dp[T][i][j], ans);
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> T >> W;
	for (int i = 1; i <= T; i++) 
		cin >> A[i];
	sol();
	return 0;
}