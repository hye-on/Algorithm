#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;
int T;
string word;
bool visit[21];
int word_size;
void backtracking(int depth,string s) {
	if (depth == word_size-1) {
		cout << s << '\n';
		return;
	}
	for (int i = depth; i < word_size; i++) {
		if (i!=depth && s[depth] == s[i])
			continue;
		char t = s[i];
		s[i] = s[depth];
		s[depth] = t;
		backtracking(depth + 1,s);
		
	}

}
int main() {

	cin >> T;
	while (T--) {
		cin >> word;
		word_size = word.size();
		sort(word.begin(), word.end());
		backtracking(0,word);	
		
		
	}

}