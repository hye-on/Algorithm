#include<iostream>
#include<functional>
#include<queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>> pqmax; //최대 힙
	priority_queue<int, vector<int>, greater<int>> pqmin; //최소 힙
	int mid;
	int n;
	cin >> n;
	int i = 0;

	while (n--) {
		int k;
		cin >> k;

		if (i == 0) {
			mid = k;
			i++;
		}
		else {
			if (k >= mid) pqmin.push(k);
			else if (k < mid) pqmax.push(k);

			int minsize = pqmin.size();
			int maxsize = pqmax.size();

			if ((minsize + maxsize + 1) % 2 == 0) {
				//전체 짝수개라면
				if (minsize <= maxsize) {
					int tmp = mid;
					mid = pqmax.top();
					pqmax.pop();
					pqmin.push(tmp);
				}
			}
			else {
				//전체 홀수개라면 
				if (minsize < maxsize) {
					pqmin.push(mid);
					mid = pqmax.top();
					pqmax.pop();
				}
				else if (minsize > maxsize) {
					pqmax.push(mid);
					mid = pqmin.top();
					pqmin.pop();
				}
			}
		}
		cout << mid << '\n';
	}
	return 0;
}