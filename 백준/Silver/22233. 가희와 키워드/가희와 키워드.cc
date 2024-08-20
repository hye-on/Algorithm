#include<iostream>
#include<set>

using namespace std;

int n, postN;
set<string>k;
string s;
//07:14
int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> postN;

	for (int i = 0; i < n; i++) {
		cin >> s;
		k.insert(s);
	}
	string pS = "",tmp="";
	
	for (int i = 0; i < postN; i++) {
		cin >> pS;
		for (int j = 0; j < pS.size(); j++) {
			if (pS[j] == ',' || j == pS.size() - 1) {
				if (j == pS.size() - 1)
					tmp += pS[j];
				if (k.find(tmp) != k.end()) {
					k.erase(tmp);
				}
				tmp = "";
				continue;
			}
			tmp += pS[j];
		}
		cout << k.size() << "\n";
	}
}