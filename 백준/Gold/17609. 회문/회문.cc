#include<iostream>
#include <string>

using namespace std;
int n;
string s;
int determinePalindrome(int start, int end, bool posPseudo) {
	while (start <= end) {
		if (s[start] != s[end]) {
			if (posPseudo) {
				if (determinePalindrome(start + 1, end, false) == 0 || determinePalindrome(start, end - 1, false) == 0)
					return 1;
			}
			return 2;
		}
		start++;
		end--;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s;
		
		cout << determinePalindrome(0, s.size() - 1, true) << "\n";
	}
}