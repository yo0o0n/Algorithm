#include <iostream>
using namespace std;
int index[100001];
int inOrder[100001];
int postOrder[100001];

void get(int inSt, int inEnd, int postSt, int postEnd) {
    if(inSt > inEnd || postSt > postEnd) return;
    int root = index[postOrder[postEnd]];
    int left = root - inSt;
    int right = inEnd - root;
    cout << inOrder[root] << " ";
    get(inSt, root - 1, postSt, postSt + left - 1);
    get(root + 1, inEnd, postSt + left, postEnd - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inOrder[i];
        index[inOrder[i]] = i;
    }
    for (int i = 1; i <= n; i++) 
        cin >> postOrder[i];
    get(1, n , 1, n);
    return 0;
}