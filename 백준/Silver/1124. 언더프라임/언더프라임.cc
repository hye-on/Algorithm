#include <iostream>
#include <algorithm>

using namespace std;



int main() {

	int arr[100001] = { 0 }, a, b;
	int count = 0;

	arr[0] = 1;
	arr[1] = 1;

	cin >> a >> b;
	for (int i = 2; i <= b; i++) {

		if (arr[i] > 0)//소수인 수는 검사 x

			continue;

		for (int j = i*2; j <= b; j += i) {//소수인 수 n 에 대하여 n의 배수가 n으로 몇번 나누어 떨어지는지 검사.
			

			for (int k = j; k%i == 0; k /= i) {

				arr[j]++;

			}

		}

	}

	



	for (int i = a; i <= b; i++)
	{//i 의 약수 개수의 약수의 개수
		if (arr[arr[i]] == 0) {

			count++;

		}

	}

	cout << count;

}
