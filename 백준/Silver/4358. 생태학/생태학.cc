#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

vector<string>name;
string temp;
int main() {
	int n = 0;
	while (true) {
		getline(cin, temp);
		if (temp.empty())
			break;
		n++;
		name.push_back(temp);
		
	}
	sort(name.begin(), name.end());
	int idx = 0;
	double cnt = 0;
	string cur = "";
	int i = 0;
	while (true) {
		cnt = 1;
		cur = name[idx];
		while (true) {
			//cout << cur << " "<<name[idx] << endl;
			idx++;
			if (idx >= n)
				break;
			if (cur != name[idx])
				break;
			cnt++;
		}
		
		//cout <<cnt<<"  " << idx << "  " << n << endl;
		cout << fixed;
		cout.precision(4);
		cout << cur << " " << cnt/n * 100<< endl;
		if (idx >= n)
			break;
		
	}
	
}