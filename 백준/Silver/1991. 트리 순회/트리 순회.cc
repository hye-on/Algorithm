#include <iostream>
#include <algorithm>
#include<cmath>
#include<queue>

using namespace std;


int n;
char tree[60]; //알파벳 보관
int abc[26]; //트리 인덱스 보관
pair<char, char> node[26];
void preOrder(char cur) {

	cout << cur;
	if(node[cur-'A'].first!='.')
		preOrder(node[cur - 'A'].first);
	if (node[cur - 'A'].second != '.')
	preOrder(node[cur - 'A'].second);
}

void inOrder(char cur) {
	
	if (node[cur - 'A'].first != '.')
		inOrder(node[cur - 'A'].first);
	cout << cur;
	if (node[cur - 'A'].second != '.')
		inOrder(node[cur - 'A'].second);
}

void postOrder(char cur) {
	if (node[cur - 'A'].first != '.')
		postOrder(node[cur - 'A'].first);
	if (node[cur - 'A'].second != '.')
		postOrder(node[cur - 'A'].second);
	cout << cur;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	char a = '.', b = '.', c = '.';
	
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		node[a - 'A'].first = b;
		node[a - 'A'].second = c;
		
	}
	
	preOrder('A');
	cout << "\n";
	inOrder('A');
	cout << "\n";
	postOrder('A');
	

}