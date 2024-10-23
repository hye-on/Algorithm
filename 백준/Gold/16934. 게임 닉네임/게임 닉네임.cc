#include<iostream>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

//05:02
// 맵 + 트라이
int j=20;
struct Trie {
	bool isEnd;
	Trie *node[26];
	Trie() {
		isEnd = false; //이거 까먹음
		for (int i = 0; i < 26; i++)
			node[i] = NULL;
	}

	void insert(char* str,int idx) {
		
		if (*str == '\0') { //포인터 빼먹음
			isEnd = true;//이거 까머음
			return;
		}
		int cur = *str - 'a';
		if (node[cur] == NULL){
			node[cur] = new Trie(); //이거 까먹음 //아직 닉네임 없으면
			j = min(j, idx);
		}

		node[cur]->insert(str + 1,idx+1);
	}

	
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = 0;
	cin >> n;
	string tmp = "";
	map<string, int>m;
	Trie* root = new Trie();
	for (int i = 0; i < n; i++) {
		j = 20;
		cin >> tmp;
		int t = m[tmp];
		root->insert(&tmp[0],0);
		if (m[tmp] == 0) {
			cout << tmp.substr(0, j + 1) << "\n";
			m[tmp] = 1;
		}
		else {
			cout << tmp+ to_string(m[tmp]) << "\n";
		}
		m[tmp]++;
		

	}
}