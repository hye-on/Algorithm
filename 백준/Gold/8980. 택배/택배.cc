#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c, m;
    cin >> n >> c >> m;

    vector<tuple<int, int, int>> v(m);  // {도착, 시작, 박스}
    for (int i = 0; i < m; i++) {
        int start, end, box;
        cin >> start >> end >> box;
        v[i] = { end, start, box };     // 도착지 기준 정렬을 위해 end를 첫번째로
    }

    sort(v.begin(), v.end());  // 기본 정렬만으로 도착지, 시작지 순 정렬됨

    vector<int> capacity(n + 1, c);
    int ans = 0;

    for (int i = 0; i < m; i++) {
        int end = get<0>(v[i]);
        int start = get<1>(v[i]);
        int box = get<2>(v[i]);

        int possible = c;
        for (int j = start; j < end; j++) {
            possible = min(possible, capacity[j]);
        }

        int mBox = min(possible, box);

        for (int j = start; j < end; j++) {
            capacity[j] -= mBox;
        }


        ans += mBox;
    }

    cout << ans << '\n';

    return 0;
}