#include<iostream>
#include<set>
#include<string>

using namespace std;

int T;
int n;
string cc[] = { "+" , "-" ," "};
int tmp = 0;
char tempC;
set<string>ans;
set<string>ans2;

void cal(string s) {
	string numS = "";
	int sum = 0;
	tempC = '+';
	for (int i = 0; i < s.size(); i++) {
		//숫자면
		if (s[i] != '+' && s[i] != '-' && s[i] != ' ') {
			numS += s[i];
		}
		else {
			if(s[i]==' ')
				continue;
			if (tempC == '+')
			{
				//cout << "numS " << numS << endl;
			
				sum += stoi(numS);
				numS = "";
			}
			else if (tempC == '-') {
				//cout << "numS " << numS << endl;
			
				sum -= stoi(numS);
				numS = "";
			}
			//else {
			//	//cout << "numS " << numS << endl;
			//	continue;
			//}
			tempC = s[i];
		}
	}
	/*if(tempC=='+')
		sum += stoi(numS);
	else if (tempC == '-') {
		sum -= stoi(numS);
	}*/
	//cout << sum << endl;
	if (numS.size() > 0) {
		if(tempC=='+')
			sum += stoi(numS);
		else if (tempC == '-') {
			sum -= stoi(numS);
	}
	}
	if (sum == 0) {
		//cout <<"?? " << tempC << "  " << numS <<"   "<<s<< endl;
		ans.insert(s.substr(0, s.size() - 1));

	}
		
}
void r(int depth,string s) {
	if (depth == n) {
		//cout << s << endl;
		cal(s);
		return;
	}
	
	for (int i = 0; i < 3; i++) {
		r(depth + 1,s+to_string(depth+1)+cc[i]);
	}
	
}
int main() {

	cin >> T;
	while (T--) {
		cin >> n;
		ans = ans2;
		r(0,"");
		for (auto a : ans)
			cout << a << endl;
		cout << endl;
	}
}