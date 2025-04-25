#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool com (const string &a, string &b) {
    if (a + b > b + a) return 1;
    else return 0;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for (int i = 0; i < numbers.size(); i++) 
        tmp.push_back(to_string(numbers[i]));
    sort(tmp.begin(), tmp.end(), com);
    
    for (int i = 0; i < tmp.size(); i++) 
        answer += tmp[i];
    if (answer[0] == '0') 
        return "0";
    return answer;
}