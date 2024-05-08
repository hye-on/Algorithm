#include<iostream>

using namespace std;

bool h[401][401]; //[i][j] i가 j보다 먼저 일어남=
int n,kk,s;

//12:51
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> kk;
	int pre = 0, af = 0;
	for (int i = 0; i < kk; i++) {
		cin >> pre >> af;
		h[pre][af] = true;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (h[i][k] && h[k][j])
				{
					h[i][j] = h[i][k] + h[k][j];
				}
			}
		}
	}


	cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		if (h[a][b])
			cout << "-1" << "\n";
		else if(h[b][a])
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
	}
}