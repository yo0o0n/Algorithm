#include <vector>
#include <string>
using namespace std;

const int INF = 1e9;
void init(vector<string> arr, vector<int> &n, vector<string> &op) {
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0)
            n.push_back(stoi(arr[i]));
        else
            op.push_back(arr[i]);
    }
}

int solution(vector<string> arr) {
    int answer = -1;
    vector<int> n;
    vector<string> op;
    init(arr, n, op);
    int maxDP[n.size()][n.size()];
    int minDP[n.size()][n.size()];
    
    for (int s = 0; s < n.size(); s++) {
        for (int i = 0; i < n.size() - s; i++) {
            int j = i + s;
            if (s == 0) {
                maxDP[i][j] = n[i];
                minDP[i][j] = n[i];
            } else {
                maxDP[i][j] = -INF;
                minDP[i][j] = INF;
                for (int k = i; k < j; k++) {
                    if(op[k] == "+") {  // 연산자 검사
                        maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] + maxDP[k + 1][j]);
                        minDP[i][j] = min(minDP[i][j], minDP[i][k] + minDP[k + 1][j]);
                    } else {
                        maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] - minDP[k + 1][j]);
                        minDP[i][j] = min(minDP[i][j], minDP[i][k] - maxDP[k + 1][j]);
                    }
                }
            }
        }
    }
    answer = maxDP[0][n.size() - 1];
    return answer;
}