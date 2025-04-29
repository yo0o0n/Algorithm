#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int dpMax[3] = { 0, }, dpMin[3] = { 0, };   // 현재 최대, 최소값
    int a[3]; // 현재 줄
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 3; i++) 
        dpMax[i] = dpMin[i] = a[i];

    for (int i = 1; i < N; i++) {
        cin >> a[0] >> a[1] >> a[2];
        int prevMax[3] = { dpMax[0], dpMax[1], dpMax[2] };  // 이전 상태 저장
        int prevMin[3] = { dpMin[0], dpMin[1], dpMin[2] };

        dpMax[0] = max(prevMax[0], prevMax[1]) + a[0];
        dpMax[1] = max({ prevMax[0], prevMax[1], prevMax[2] }) + a[1];
        dpMax[2] = max(prevMax[1], prevMax[2]) + a[2];

        dpMin[0] = min(prevMin[0], prevMin[1]) + a[0];
        dpMin[1] = min({ prevMin[0], prevMin[1], prevMin[2] }) + a[1];
        dpMin[2] = min(prevMin[1], prevMin[2]) + a[2];
    }
    cout << max({ dpMax[0], dpMax[1], dpMax[2] }) << " " << min({ dpMin[0], dpMin[1], dpMin[2] });
    return 0;
}