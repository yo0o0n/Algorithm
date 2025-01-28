#include<iostream>
#include<queue>
#define ll long long
using namespace std;
vector<pair<ll, ll>> city[100001];
priority_queue<pair<ll, ll>> pq;
ll dist[100001];
ll N, M, K;

void dijk(){
    pair<ll, ll> result = {-1, -1}; // 번호, 거리 순
    while(!pq.empty()) {
        ll nowPos = pq.top().second;
        ll nowCost = -pq.top().first;
        pq.pop();
        if(dist[nowPos] < nowCost) continue;
        for(ll i = 0; i < city[nowPos].size(); i++) {
            ll next = city[nowPos][i].first;
            ll cost = city[nowPos][i].second + nowCost;
            if(dist[next] > cost) {
                pq.push({-cost, next});
                dist[next] = cost;
            }
        }
    }
    for(ll i = 1; i <= N; i++) {
        if(result.second < dist[i])
            result = {i, dist[i]};
    }
    cout << result.first << '\n' << result.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(ll i = 0; i <= N; i++) dist[i] = 1e18;
    for(ll i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        city[b].push_back({a, c});
    }
    for(ll i = 0; i < K; i++) {
        ll s; cin >> s;
        pq.push({0, s});
        dist[s] = 0;
    }
    dijk();
    return 0;
}