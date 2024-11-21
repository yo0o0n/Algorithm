#include <string>
#include <vector>

using namespace std;

vector<int> purse(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] * n;
        n *= -1;
    }
    return v;
}

long long solution(vector<int> sequence) {
    vector<int> s1 = purse(sequence, 1);    // 1로 시작
    vector<int> s2 = purse(sequence, -1);    // -1로 시작
    long long answer = 0;
    long long dp1[s1.size()];   // 1 dp 배열
    long long dp2[s2.size()];   // -1 dp 배열
    dp1[0] = s1[0];
    dp2[0] = s2[0];
    for (int i = 1; i < s1.size(); i++) {
        dp1[i] = max(dp1[i - 1] + (long long)s1[i], (long long)s1[i]);   // 자료형 치환
        answer = max(answer, dp1[i]);
    }
    for (int i = 1; i < s2.size(); i++) {
        dp2[i] = max(dp2[i - 1] + (long long)s2[i], (long long)s2[i]);
        answer = max(answer, dp2[i]);
    }
    if(sequence.size() == 1) {
        answer = max(s1[0], s2[0]);
        return answer;
    }
    return answer;
}