#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int T,n;
//2 5 5 4 5 6 3 7 6 6
//1 2 3 4 5 6 7 8 9 0
int num[] = { 6,2,5,5,4,5,6,3,7,6 };
string dpB[101] = { "0","0","1","7","4","5","9","8","0", };
string dpS[101] = { "0","0","1","7","4","2","6","8",};
int main() {
	cin >> T;
	string tempB = "",tempS="";
	for (int i = 8; i < 101; i++)
		dpS[i] = "99999999999999999999999999999999999999999999";
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < i; j++) {
			if (!(dpB[i - j] == "0" || dpB[j] == "0"))
			{
				tempB = dpB[i - j] + dpB[j];
				if (dpB[i].length() < tempB.length())
					dpB[i] = tempB;
				else if (dpB[i].length() == tempB.length()) {
					tempB = max(dpB[i], tempB);
					dpB[i] = tempB;
				}
			}
			if (!(dpS[i - j] == "0"))
			{
				if(j==6)
					tempS = dpS[i - j] + "0";
				else
					tempS = dpS[i - j] + dpS[j];
				if (dpS[i].length() > tempS.length())
					dpS[i] = tempS;
				else if (dpS[i].length() == tempS.length()) {
					tempS = min(dpS[i], tempS);
					dpS[i] = tempS;
				}
			}
		}
	}
	//dpS[6] = "6";
	/*for (int i=1;i<101;i++)
		cout << i<<"  "<<dpS[i] <<" "<<dpB[i] <<endl;*/
	while (T--) {
		cin >> n;
		
		cout << dpS[n] << " " << dpB[n] << endl;
	}
}