#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	int dp[3][3][3][3];
	int tcnt = 0, gcnt = 0, fcnt = 0, pcnt = 0, ans = 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;
	for(int i = 0; i < N; i++) {
		char m;
		cin >> m;
		if (m == 'T')
			tcnt = (tcnt + 1) % 3;
		else if (m == 'G')
			gcnt = (gcnt + 1) % 3;
		else if (m == 'F')
			fcnt = (fcnt + 1) % 3;
		else if (m == 'P')
			pcnt = (pcnt + 1) % 3;
		ans += dp[tcnt][gcnt][fcnt][pcnt];
		dp[tcnt][gcnt][fcnt][pcnt] += 1;
	}
	cout << ans;
	return 0;
}
