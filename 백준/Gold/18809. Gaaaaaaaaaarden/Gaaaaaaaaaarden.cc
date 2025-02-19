#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, g, r;
int map[50][50];
vector<int> num;  // 배양액을 뿌릴 수 있는 땅의 위치들

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
pair<int, int> area[50][50];  // (색깔, 시간) 정보 저장

// BFS 함수: 꽃의 개수를 반환
int bfs(queue<pair<int, pair<int, int>>>& q) {
    int flower_cnt = 0;

    while(!q.empty()) {
        int y = q.front().first / m;
        int x = q.front().first % m;    
        int color = q.front().second.first;
        int time = q.front().second.second;
        q.pop();

        // 이미 꽃이 된 위치면 건너뜀
        if(area[y][x].first == 3)
            continue;
    
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 맵 범위 체크 및 호수 체크
            if(ny >= n || ny < 0 || nx >= m || nx < 0 || map[ny][nx] == 0)
                continue;
            
            // 같은 색상이 이미 방문한 곳이면 건너뜀
            if(area[ny][nx].first == color)
                continue;
            
            if(area[ny][nx].first == 0) {
                // 아직 방문하지 않은 곳
                area[ny][nx].first = color;
                area[ny][nx].second = time + 1;
                q.push({ny * m + nx, {color, time + 1}});
            }
            else if(area[ny][nx].first != 3 && area[ny][nx].second == time + 1) {
                // 다른 색상이 같은 시간에 도달 -> 꽃 피우기
                flower_cnt++;
                area[ny][nx].first = 3;  // 3은 꽃을 의미
            }
        }
    }

    return flower_cnt;
}

int main() {
    // 입력 받기
    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                num.push_back(m * i + j);  
            }
        }
    }

    int answer = 0;
    
   
    sort(num.begin(), num.end());
    
    // num에서 g+r개 선택하기 위한 조합 마스크
    // 0: 선택되지 않음, 1: 선택됨
    vector<int> combination(num.size(), 0);
    
    // 마지막 (g+r)개 위치를 1로 설정 - 조합 생성 시작 상태
    fill(combination.end() - (g+r), combination.end(), 1);
    
    //  num 배열에서 (g+r)개 위치 선택 (조합)
    do {
      
        vector<int> positions;
        for(int i = 0; i < num.size(); i++) {
            if(combination[i]) {
                positions.push_back(num[i]);
            }
        }
        
        // 2단계: 선택된 (g+r)개 위치 중 g개를 초록색으로 선택하기 위한 마스크
        // 0: 빨간색, 1: 초록색
        vector<int> green_mask(g+r, 0);
        fill(green_mask.end() - g, green_mask.end(), 1);
        
        // 선택된 위치에서 초록색 위치 결정 (조합)
        do {
            // 각 시도마다 area 배열 초기화
            for(int i = 0; i < 50; i++) {
                for(int j = 0; j < 50; j++) {
                    area[i][j] = {0, 0};
                }
            }

            queue<pair<int, pair<int, int>>> q;  // (위치, (색상, 시간))
            for(int i = 0; i < g+r; i++) {
             
                int color = green_mask[i] ? 1 : 2;
                q.push({positions[i], {color, 0}});  
                area[positions[i] / m][positions[i] % m].first = color;
            }
            
         
            answer = max(answer, bfs(q));
            
        } while(next_permutation(green_mask.begin(), green_mask.end()));
       
        
    } while(next_permutation(combination.begin(), combination.end()));
    // 모든 가능한 위치 조합 시도
    
    cout << answer;
    return 0;
}