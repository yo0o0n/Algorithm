#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

ll dp[101] = { 0, };
int num[9] = { 0,0,1,7,4,2,0,8,10 };
int tc;

void sol() {    // 최소값 메모이제이션 -> 배열에 저장
    for (int i = 1; i <= 8; i++)
        dp[i] = num[i];
    dp[6] = 6;

    for (int i = 9; i <= 100; i++) {
        dp[i] = 888888888888888;
        for (int j = 2; j < 8; j++) {
            dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
    sol();
    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;
        cout << dp[n] << " ";

        while(n) {
            if (n % 2 != 0) {
                cout << 7;
                n -= 3;
            } else {
                cout << 1;
                n -= 2;
            }
        }
        cout << endl;
    }
    return 0;
}