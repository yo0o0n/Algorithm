#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll> seg;
vector<ll> num;
int n, m, k;
ll init(int st, int end, int node) {
    if (st == end)
        return seg[node] = num[st];
    int mid = (st + end) >> 1;
    return seg[node] = init(st, mid, node << 1) + init(mid + 1, end, (node << 1) + 1);
}

ll sum(int st, int end, int left, int right, int node) {
    if (left > end || right < st)
        return 0;
    if (left <= st && right >= end)
        return seg[node];
    int mid = (st + end) >> 1;
    return sum(st, mid, left, right, node << 1) + sum(mid + 1, end, left, right, (node << 1) + 1);
}

void update(int st, int end, int target, ll dif, int node) {
    if (target > end || target < st) return;
    seg[node] += dif;
    if (st == end) return;
    int mid = (st + end) >> 1;
    update(st, mid, target, dif, node << 1);
    update(mid + 1, end, target, dif, (node << 1) + 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int h = ceil(log2(n));
    int treeSize = 1 << (h + 1);
    seg = vector<ll>(treeSize);
    num.push_back(0);
    for (int i = 0; i < n; ++i) {
        ll inte;
        cin >> inte;
        num.push_back(inte);
    }
    init(1, n, 1);
    for (int i = 0; i < m + k; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ll dif = c - num[b];
            num[b] = c;
            update(1, n, b, dif, 1);
        }
        else
            cout << sum(1, n, b, c, 1) << "\n";
    }
    return 0;
}