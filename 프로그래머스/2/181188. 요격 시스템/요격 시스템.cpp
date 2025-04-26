#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool com(vector<int> &a, vector<int> &b) {
    if (a[1] < b[1]) return 1;
    else return 0;
}

int solution(vector<vector<int>> targets) {
    int e = 0;
    int answer = 0;
    sort(targets.begin(), targets.end(), com);
    for (int i = 0; i < targets.size(); i++) {
        if (targets[i][0] >= e) {   // 새로운 요격 미사일
            e = targets[i][1];
            answer++;
        }
    }
    return answer;
}