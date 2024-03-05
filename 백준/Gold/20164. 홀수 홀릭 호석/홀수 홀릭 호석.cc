#include<iostream>
#include<string>
using namespace std;

int N,new_n;
int min_n = 200000000, max_n,cnt;
string s1, s2, s3;

int cal(string ss) {
	int odd = 0;
	for (int i = 0; i < ss.size(); i++) {
		//cout<<"ss :"<<ss<<"  " << ss[i] - '0' << endl;
		if ((ss[i] - '0') % 2)
			odd++;
	}
	return odd;
}
void sol(string s, int cnt) {
	int size = s.size();
	if (size == 1) {
		if (cnt < min_n)
			min_n = cnt;
		if (cnt > max_n)
			max_n = cnt;
		return;
	}
	else if (size == 2) {
		new_n = (s[0] - '0') + (s[1] - '0');
		sol(to_string(new_n), cnt + cal(to_string(new_n)));
	}
	for (int i = 1; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			s1 = s.substr(0, i);
			s2 = s.substr(i, j - i);
			s3 = s.substr(j);
			new_n = stoi(s1) + stoi(s2) + stoi(s3);

			sol(to_string(new_n), cnt + cal(to_string(new_n)));
		}
	}
}




int main(){
	cin >> N;
	
	sol(to_string(N), cal(to_string(N)));
	cout << min_n << " " << max_n;

}