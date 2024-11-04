#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

//분할 정복
//왼쪽, 오른쪽, 걸치기
// O(N log N)

int n;
vector<int>histogram(100000);

int recursion(int start, int end) {
	if (start == end)
		return histogram[start];

	int mid = (start + end) / 2;
	int left = mid, right = mid + 1;
	int high = min(histogram[mid], histogram[mid + 1]);
	int maxN = 2 * high;
	while (start<left || right < end) {

	
		// 오른쪽이 더 크거나 왼쪽이 더 갈 곳이 없을 때
		if (right < end && (start == left || histogram[left - 1] < histogram[right + 1])) {
			right++;
			high = min(high, histogram[right]);
		}
		else {
			left--;
			high = min(high, histogram[left]);
		}
		maxN = max(maxN, high * (right - left + 1));
	}

	return max({ maxN, recursion(start,mid),recursion(mid + 1,end) });
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> histogram[i];
	}

	cout << recursion(0, n - 1);

}
