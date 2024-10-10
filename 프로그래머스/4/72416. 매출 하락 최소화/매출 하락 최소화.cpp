#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 팀 구조를 저장하는 맵 (부모-자식 관계)
unordered_map<int, vector<int>> team; 

// dfs 함수는 pair를 반환합니다. 
// first는 리더가 참석하지 않을 경우의 손해비용, second는 리더가 참석할 경우의 손해비용
pair<int, int> dfs(vector<int>& sales, int lead) {
    // 리프 노드일 경우 
    
    if (team.find(lead) == team.end()) {
        return {0, sales[lead - 1]}; // 참석 안 하면 0, 참석하면 매출액
    } else {
        // 리더가 참석하지 않을 때 팀원의 최소 비용 합계
        int noAttendCost = 0; 
        
        // 최소 손해비용 차이
        int minDiff = 1e9; 
        
        // 팀원이 참석하는 것이 더 이득인 경우
        bool needAttend = false; 

        for (auto sub : team[lead]) {
            // 재귀적으로 dfs를 호출하여 손해비용 계산
            auto cost = dfs(sales, sub);

            // 팀원이 참석하든 안 하든 최소 손해비용 선택
            noAttendCost += min(cost.first, cost.second);

            // 팀원이 참석하는 것이 더 이득인 경우
            if (cost.first >= cost.second) needAttend = true;

            // 리더가 참석하지 않을 경우 팀원 중 최소 손해 차이값
            minDiff = min(minDiff, cost.second - cost.first);
        }

        // 팀원이 참석하는 것이 더 이득이면 리더는 불참
        if (needAttend) {
            return {noAttendCost, sales[lead - 1] + noAttendCost};
        }
        // 그렇지 않으면 최소 손해비용 차이가 적은 팀원을 참석시킴
        else {
            return {noAttendCost + minDiff, sales[lead - 1] + noAttendCost};
        }
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    // 팀 관계 설정
    for (auto link : links) {
        team[link[0]].push_back(link[1]);
    }
    // 1번 리더에서 시작하여 dfs 호출
    auto result = dfs(sales, 1);

    // 최소 손해비용 반환
    return min(result.first, result.second);
}
