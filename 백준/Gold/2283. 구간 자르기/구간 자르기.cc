#include<iostream>
#include<algorithm>
using namespace std;


// 누적합 + 투포인터
//1:45 ~


//1,000,000 * 1000 -> 시간초과
//1. 하나의 배열에 양 끝에 표시   , 1, -1
//2. 누적합 구하기
//3. 투포인터,or 구간합으로 구하기
int n, k;

int arr[1000002];
int sum;

int main() {
	cin >> n >> k; 
	int start = 0, end = 0,maxIdx=0;
	
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		arr[start] += 1;
		arr[end ] += -1;
		sum += end - start + 1;
		maxIdx = max(end, maxIdx);
	}

	for (int i = 0; i <=maxIdx; i++)
		arr[i + 1] += arr[i];

	int point = 0;
	int sectionSum = 0;

	//투포인터
	int left = 0, right = 0;
	bool findAns = false;
	for (int i= 0; i <= maxIdx; i++) {
		while (point <= maxIdx && sectionSum<=k) {
			if (sectionSum == k) {
				left = i;
				right = point;
				findAns = true;
				break;
			}
			if (findAns)
				break;
			sectionSum += arr[point];
			point++;
			
		}

		if (findAns)
			break;
		sectionSum -= arr[i];
	}

	cout << left << ' ' << right;
	
}