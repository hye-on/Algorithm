#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

int n, c, m; //마을 개수, 용량, 박스 정보

//04:40

// 도착지가 빠른 택배를 우선으로 태운다 (가중치가 없기 때문에)
// //마을정보 정렬 
// 내릴 택배를 바로 알기 위해 우선순위큐를 사용하여 {-마을 번호, 택배 개수} 저장 

// 1->4 50, 2->3 40 . 40개 빼고 40개 넣기. 그리디

int main() {


	cin >> n >> c;
	cin>> m;

	vector<tuple<int, int, int>>v(m); //출발 마을 번호, 도착 마을번호, 박스 개수
	int a = 0, b = 0, d = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		v[i] = { a,b,d };
	}
	sort(v.begin(), v.end());

	priority_queue<pair<int, int>>pq; //{-마을 번호, 택배 개수}
	int ans = 0;
	int cnt = 0;

	int idx = 0;
	for (int i = 1; i <= n; i++) {

		//택배 내리기
		//택배가 존재하고 도착지에 도착한 택배인 경우
		while (!pq.empty() && -pq.top().first == i) {
		//	cout << "도착 " << -pq.top().first << " " << pq.top().second << endl;
			ans += pq.top().second;
			cnt -= pq.top().second;
			pq.pop();
		}

		//해당 마을까지 idx++
		while (idx<m && get<0>(v[idx]) < i) {
			idx++;
		}

		//택배 넣기
		for (idx; idx < m; idx++) {
			if (get<0>(v[idx]) != i)
				break;
			int now = get<0>(v[idx]);
			int next = get<1>(v[idx]);
			int box = get<2>(v[idx]);

			//실을 수 있는 만큼 실음
			int rest = c - cnt;
			pair<int, int>tmp = { -next,min(rest,box) };
			//pq.push({ -next,min(rest,box)});
		
			cnt += min(rest, box);
			
		//	cout << "택배 실음 " << now << " -> " << next << "  : " << min(rest, box) << endl;
		//	cout << cnt << endl;
			//남은 박스 개수
			box = box - min(rest, box);

			//전부 다 실은 경우
			if (box <= 0) {
				pq.push({ tmp });
				continue;
			}
			else { // 택배 용량이 다 차서 일부만 실거나 못실은 경우

				//택배에서 제일 빠른 도착지보다 빠르면 그 택배를 빼고 지금 택배를 넣음
				while (!pq.empty()) {

					int nx = -pq.top().first; //택배에 있는 것중에 제일 빠른 마을
					int ex_box = pq.top().second;

					if (nx<=next) { // 택배에 있는 것이 더 빠른 경우
						
						break;
					}
					else if (next < nx) { // 더 빠른 마을 배송인 경우
						int bn = ex_box - box; //필요한 만큼만 택배에서 내림 1)50-30 , 30-50
						pq.pop();

						//일부만 택배에서 내려도 됨
						//1)
						if (bn >= 0) {
			//				cout << "일부 택배 실음 " << now << " -> " << next << "  : " << bn <<" : "<<box << endl;
							pq.push({ -nx,bn }); //필요한 만큼 뺸 후 다시 담음
							pq.push({ -next,box }); // 택배 담음
							break;
						}
						else {//2) 다른 택배도 더 내려야 함
			//				cout << "일부 택배 실음2 " << now << " -> " << next << "  : "  << " : " << ex_box << endl;

							pq.push({ -next,ex_box }); // 내린 만큼만 담음
							box -= ex_box; //택배에 실고 담은 박스 수 갱신
						}
					}
					
				}
				
				pq.push({ tmp });
			}
			
		}
	}

	cout << ans;
}