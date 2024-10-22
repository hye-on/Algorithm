#include<iostream>

using namespace std;
int n, m;


struct Trie {
	bool isEnd;
	Trie* node[26];

	Trie() {
		isEnd = false;
		for (int i = 0; i < 26; i++)
			node[i] = NULL;
	}

	void insert(char* str) {
		if (*str == '\0') {
			isEnd = true;
			return;
		}

		int cur = *str - 'a';
		if (node[cur] == NULL)
			node[cur] = new Trie();
		node[cur]->insert(str + 1);

	}

	bool find(char *str) {
		
		if (*str == '\0') {
			return true;
		}
	
		int cur = *str - 'a';
		if (node[cur] == NULL)
			return false;
		return node[cur]->find(str + 1);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string tmp = "",t="";
	Trie* root = new Trie;
	for (int i = 0; i < n; i++) {//트라이 insert
		cin >> tmp;
		root->insert(&tmp[0]);
		
	}

	int ans = 0;
	for (int j = 0; j < m; j++) { // 트라이 find
		t = "";
		cin >> t;
		
		if (root->find(&t[0])) {
			ans++;

		}
	}

	cout << ans << "\n";
}