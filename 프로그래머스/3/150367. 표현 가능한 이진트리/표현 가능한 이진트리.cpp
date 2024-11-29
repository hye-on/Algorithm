
#include <string>
#include <vector>
#include <cstring>
using namespace std;

long long y = 0;
bool check[64], visit[64];
//조건 : 0아래에는 1이 있으면 안된다.
// 0이면 dfs를 중단하므로 그 아래 1이 있더라도 y를 만드는데 반영되지 않음
// 즉 x랑 y랑 다른 숫자가 됨. 
//dx : now를 기준으로 양 옆에 자식 노드까지의 거리 
void dfs(int now, int dx){
    visit[now] = true; y += (1LL << now);
    
    //next는 자식 노드 
    for (int next : {now - dx, now + dx})
        
    //1이고 방문한 적 없으면 
    if (check[next] && !visit[next])
        dfs(next, dx / 2);
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (long long x : numbers){
        bool flag = false;
        memset(check, 0, sizeof(check));
        //비트마스크를 통해 2진수로 바꾼다.
        //long long은 64비트 0~63비트 사용함
        // 63번째 비트는 부호를 결정하는 비트라서 제외하고 62번째 비트까지 사용
        for (int k = 0; k < 63; k++){
            if ((1LL << k) & x)
                check[k] = true;
        }
        //루트가 될 수 있는 노드 만약 depth가 4면 7이 루트 노드 
        //만약 포화이진트리 노드 개수가 64개면 중간에 있는 31이 루트 노드 (0부터 시작)
        // n번째가 루트노드일 때 dfs로 숫자를 만들기
        for (int root : {0, 1, 3, 7, 15, 31})
        if (check[root]){
            y = 0;
            memset(visit, 0, sizeof(visit));
            dfs(root, (root + 1) / 2);
            // 숫자가 같으면 flag를 true로 만들어서 탈출
            //다르면 다음 root로 숫자를 만들어서 검사 
            if (flag = (x == y)) break;
        }

        answer.push_back(flag);
    }
    return answer;
}