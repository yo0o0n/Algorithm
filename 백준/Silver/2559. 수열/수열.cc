#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	int max = INT_MIN;
	cin >> n >> k;
	vector<int> tem(n + 1, 0);
	vector<int> sum(n + 1, 0);

	for (int i = 0; i < n; i++) {
		cin >> tem[i + 1];
		tem[i + 1] += tem[i];
	}
	for (int i = k; i <= n; i++) {
		int ans = tem[i] - tem[i - k];
		if (ans > max) 
			max = ans;
	}
	cout << max;
	return 0;
}