#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(maxheap.empty())
            maxheap.push(a);
        else if (maxheap.size() == minheap.size())
            maxheap.push(a);
        else
            minheap.push(a);
        if (!maxheap.empty() && !minheap.empty() && (maxheap.top() > minheap.top())) {
            int max_val, min_val;
            max_val = maxheap.top();
            min_val = minheap.top();
            maxheap.pop();
            minheap.pop();
            maxheap.push(min_val);
            minheap.push(max_val);
        }
        cout << maxheap.top() << "\n";
    }
    return 0;
}