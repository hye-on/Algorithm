#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, k;

priority_queue<int,vector<int>,greater<int>>bag;
priority_queue<int>v;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>num; //무게 가치



long long ans;
int main() {
	cin >> n >> k;

	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		cin >>a >> b;
		num.push({ a,b });
	}
	int tmp = 0;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		bag.push(tmp);
	}
	
	
	for (int i = 0; i < k; i++) {
		
		while (!num.empty() &&  num.top().first <= bag.top()) { //  가방에 들어갈 수 있는 것들 다 큐에 담기
			v.push(num.top().second);
			num.pop();
		}
		if (!v.empty()) {
			ans += v.top();
			v.pop();
			
		}
		bag.pop();
	}
	cout << ans;
}