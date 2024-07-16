#include<iostream>

using namespace std;
string s;
string rs;
string tmp;

int main() {
	

	cin >> s;
	cin >> rs;
	for (int i = 0; i < s.size(); i++) {
		//뒤에 글자가 같지 않으면 넣어줌
		
		tmp += s[i];
		
		if (tmp.size() < rs.size())
			continue;
		//폭발 문자열이면 삭제
		if (tmp.substr(tmp.size() - rs.size(), rs.size()) == rs) {
			tmp.erase(tmp.size() - rs.size(), rs.size());
		}

		
	}
	if (tmp.size() == 0)
		cout << "FRULA" << "\n";
	else
		cout << tmp << "\n";
}
