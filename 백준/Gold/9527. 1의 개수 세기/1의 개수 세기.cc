#include <iostream>
using namespace std;
long long a, b;

long long cnt(long long a) {
    int i = 1;  // 자리수
    long long sum = 0;
    long long rest = 0;
    while (a) {
        rest |= (a & 1LL) << (i - 1);
        sum += (a >> 1) * (1LL << (i - 1)); // 몫 더해주기
        sum += (rest >> (i - 1)) * (rest - (1LL << (i - 1)));   // 나머지
        a = a >> 1;
        i++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    cout << cnt(b + 1) - cnt(a) << "\n";
    return 0;
}
