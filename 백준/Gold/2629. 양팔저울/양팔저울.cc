#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int chu, bead, check; // 추, 구슬, 확인
int weight[31]; // 무게 저장
bool dp[31][15001]; // [추의개수][추의무게]
void sol(int i, int w) {
    if (i > chu || dp[i][w]) return;
    dp[i][w] = 1;
    sol(i + 1, w + weight[i]);
    sol(i + 1, abs(w - weight[i]));
    sol(i + 1, w);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> chu;
    for (int i = 0; i < chu; i++)
        cin >> weight[i];
    sol(0, 0);
    cin >> bead;
    for (int i = 0; i < bead; i++) {
        cin >> check;
        if (check > 15000) cout << "N ";
        else if (dp[chu][check]) cout << "Y ";
        else cout << "N ";
    }
}