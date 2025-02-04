#include <iostream>
using namespace std;

using LL = int64_t;
LL a;
LL higherA = 0;
LL lowerA = 0;
LL one = 1;
LL mask = 3;
int cnt = 0;

void lower() {
    lowerA = a ^ mask;    // 10 -> 01
    lowerA = (lowerA / one) * one;
    LL n = (one >> 1);
    int ans = cnt;
    while(n && ans--) {
        lowerA += n;
        n >>= 1;
    }
}

void higher() {
    higherA = a ^ mask;    // 01 -> 10
    higherA = (higherA / one) * one;
    LL n = 1;
    int ans = cnt;
    while (n < one && ans--) {
        higherA += n;
        n <<= 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a;
    while(1) {
        if (lowerA && higherA) break;
        if (one > a) break;
        if ((a & mask) == (one << 1)) lower();
        if ((a & mask) == one) higher();
        if (a & one) ++cnt;
        one <<= 1;
        mask <<= 1;
    }
    cout << lowerA << " " << higherA << endl;
    return 0;
}