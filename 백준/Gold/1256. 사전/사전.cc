#include<iostream>
#include<algorithm>
#define MAX 1000000000
using namespace std;

int comb[201][201];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) comb[i][j] = 1;
			else {
				comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
				if (comb[i][j] > MAX) comb[i][j] = MAX + 1;
			}
		}
	}
	if (comb[n + m][m] < k) {
		cout << "-1";
		return 0;
	}
	while (n + m > 0) {
		if (comb[n + m - 1][m] < k) {
			cout << 'z';
			k -= comb[n + m - 1][m];
			m--;
		} else {
			cout << 'a';
			n--;
		}
	}
	return 0;
}