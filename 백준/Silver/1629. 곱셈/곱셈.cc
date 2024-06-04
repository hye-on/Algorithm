#include<iostream>

using namespace std;
long long A, B, C;
long long T;
long long recursion(int b) {
	if (b == 0) return 1;
	if (b == 1) return A % C;
	 T = recursion(b/2) % C;

	if (b % 2 == 0) {
		return T * T % C;
	}
	else {
		return T * T % C * A % C;
	}
}
int main() {
	cin >> A >> B >> C;
	cout<< recursion(B);
	
}