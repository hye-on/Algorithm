#include <iostream>
#include <string>

using namespace std;

char input[10000][11];
struct Trie {
	bool isEnd;
	Trie* node[10];

	Trie() {
		isEnd = false;
		for (int i = 0; i < 10; i++) {
			node[i] = NULL;
		}
	}

	void insert(char * str) {
		if (*str == '\0') {
			isEnd = true;
			return;
		}
		int cur = *str - '0';
		if(node[cur]==NULL)node[cur] = new Trie();
		node[cur]->insert(str + 1);
		
	}

	bool find(char* str) {
		if (*str == '\0') {
			return false;
		}
		if (isEnd == true)
			return true;

		int cur = *str - '0';
		if (node[cur] == NULL)
			return false;
		return node[cur]->find(str + 1);
	}


};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		Trie* root = new Trie();
		for (int i = 0; i < n; i++) {
			cin >> input[i];
			root->insert(input[i]);
		}
		int i;
		bool ans = true;
		for (i = 0; i < n; i++) {
			if (root->find(input[i])) {
				ans = false;
				
				break;
			}
		}
		ans ? cout << "YES\n": cout << "NO\n";
	}

	return 0;
}