#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define INF 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long n, r;
    cin >> n >> r;
    
    // 도시 이름 압축: 같은 이름이면 동일한 정점으로 취급
    map<string, int> city_index;
    vector<string> unique_cities;
    string name;
    for (long i = 0; i < n; i++) {
        cin >> name;
        if (city_index.find(name) == city_index.end()) {
            city_index[name] = unique_cities.size();
            unique_cities.push_back(name);
        }
    }
    int uniqueCount = unique_cities.size();
    
    long m;
    cin >> m;
    if (m == 1) {
        cout << "No";
        return 0;
    }
    vector<int> route(m);
    string routeCity;
    for (int i = 0; i < m; i++) {
        cin >> routeCity;
        route[i] = city_index[routeCity];
    }
    
    long k;
    cin >> k;
    
    // 비용 행렬 초기화 (모든 비용은 2배로 계산)
    vector<vector<int>> cost(uniqueCount, vector<int>(uniqueCount, INF));
    vector<vector<int>> pass_cost(uniqueCount, vector<int>(uniqueCount, INF));
    
    // 자기 자신으로 가는 비용은 0
    for (int i = 0; i < uniqueCount; i++) {
        cost[i][i] = 0;
        pass_cost[i][i] = 0;
    }
    
    // 교통수단 정보 입력
    for (int i = 0; i < k; i++) {
        string t, s, d;
        int c;
        cin >> t >> s >> d >> c;
        // 모든 비용을 2배로 계산
        int normal = c * 2;
        int discount;
        if (t == "S-Train" || t == "V-Train") {
            // 50% 할인: (2*c)/2 = c
            discount = normal / 2;
        } else if (t == "Mugunghwa" || t == "ITX-Saemaeul" || t == "ITX-Cheongchun") {
            // 무료
            discount = 0;
        } else {
            // 할인 없음
            discount = normal;
        }
        
        int u = city_index[s], v = city_index[d];
        cost[u][v] = min(cost[u][v], normal);
        cost[v][u] = min(cost[v][u], normal);
        pass_cost[u][v] = min(pass_cost[u][v], discount);
        pass_cost[v][u] = min(pass_cost[v][u], discount);
    }
    
    // 플로이드 와샬 알고리즘 적용
    for (int k = 0; k < uniqueCount; k++) {
        for (int i = 0; i < uniqueCount; i++) {
            for (int j = 0; j < uniqueCount; j++) {
                if (cost[i][k] < INF && cost[k][j] < INF)
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                if (pass_cost[i][k] < INF && pass_cost[k][j] < INF)
                    pass_cost[i][j] = min(pass_cost[i][j], pass_cost[i][k] + pass_cost[k][j]);
            }
        }
    }
    
    // 총 경로 비용 계산 (내일로 티켓 구매 시에는 티켓 가격도 2배)
    long long total_normal = 0;
    long long total_pass = r * 2; // 티켓 가격도 2배하여 더함
    for (int i = 0; i < m - 1; i++) {
        int u = route[i];
        int v = route[i+1];
        total_normal += cost[u][v];
        total_pass += pass_cost[u][v];
    }
    
    cout << (total_pass < total_normal ? "Yes" : "No");
    return 0;
}
