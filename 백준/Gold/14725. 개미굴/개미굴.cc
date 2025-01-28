#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

struct node {
	bool finish;
	map<string, int> child;
	string cur;
	node(string s) {
		finish = false;
		cur = s;
		child.clear();
	}
};
vector<node> trie;

int insert(int n, string s) {
	if (trie[n].child[s] == 0) {
		trie[n].child[s] = trie.size();
		trie.push_back(s);
	}
	return trie[n].child[s];
}

void dfs(int cur, int d) {
	if (cur != 0) {
		for (int i = 0; i < d - 1; i++) cout << "--";
		cout << trie[cur].cur << endl; // 먹이 정보
	}
	for (auto i = trie[cur].child.begin(); i != trie[cur].child.end(); i++) {
		dfs(i->second, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	trie.push_back(node(""));

	while (N--) {
		int end;
		int eat = 0;
		cin >> end;
		while (end--) {
			string s;
			cin >> s;
			eat = insert(eat, s);
		}
	}
	dfs(0, 0);
	return 0;
}