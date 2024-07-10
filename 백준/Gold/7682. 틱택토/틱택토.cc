#include<iostream>

using namespace std;

string s;
int x , o ;
int xWin, oWin;

bool checkCounts(string &ss) {
	x = 0, o = 0;
	for (int i=0; i < ss.size(); i++) {
		if (s[i] == 'X')
			x++;
		else if (s[i] == 'O')
			o++;
	}
	if (x == o + 1 || x == o )
		return true;
	else
		return false;
}

void checkRow(string &ss) {
	for (int i=0; i < 7; i+=3) {
		if (ss[i] == '.')
			continue;
		if (ss[i] == ss[i + 1] && ss[i] == ss[i + 2]) {
			 
			if (ss[i] == 'O')
				oWin++;
			else
				xWin++;
			
		}
			
	}
}

void checkCol(string& ss) {
	for (int i = 0; i < 3; i++) {
		if (ss[i] == '.')
			continue;
		if (ss[i] == ss[i + 3] && ss[i] == ss[i + 6]) {
			if (ss[i] == 'O')
				oWin++;
			else
				xWin++;
		}
			
	}
}

void checkCross(string& ss) {
	if (ss[0] != '.' && ss[0] == ss[4] && ss[0] == ss[8]) {
		if (ss[0] == 'O')
			oWin++;
		else
			xWin++;
	}
	if (ss[2]!='.' && ss[2] == ss[4] && ss[2] == ss[6]){
		if (ss[2] == 'O')
			oWin++;
		else
			xWin++;
	}

}
int main() {

	while (true) {
		cin >> s;
		if (s == "end")
			break;
		if (!checkCounts(s)) {
			cout << "invalid" << "\n";
			continue;
		}
	
		oWin = 0, xWin = 0;
		checkCol(s);
		checkRow(s); 
		checkCross(s);
		//cout << xWin << "  " << oWin << endl;
		if (oWin == 0 && xWin == 0) {
			//승부가 안남 
			if(x==5)
				cout << "valid" << "\n";
			else
				cout << "invalid" << "\n";
			continue;
		}
		else if (oWin + xWin >=1) {
			if(oWin==1&& xWin==0 && x==o)//O가 이긴 경우에는 x랑 o랑 개수 똑같아야 함
				cout << "valid" << "\n";
			else if(oWin==1)
				cout << "invalid" << "\n";
			else if(x==o+1)
				cout << "valid" << "\n";
			else
				cout << "invalid" << "\n";
			continue;

		}
		cout << "invalid" << "\n";
			
		
	}
}