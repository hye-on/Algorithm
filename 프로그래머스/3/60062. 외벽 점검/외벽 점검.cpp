#include <vector>
#include <algorithm>

using namespace std;

//더 좋은 풀이 
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e8;
    int w_size = weak.size();
    
    //원형 탐색을 위한 전처리 
    for(int i=0; i<w_size-1; ++i) {
        weak.push_back(weak[i] + n);
    }
    
    sort(dist.begin(), dist.end()); 
    
    do {
    //모든 취약점을 각각 시작점에서 해서 검사한다. 
        for(int i=0; i<w_size; ++i) { 
        //시작 취약점과 마지막 취약점 (1) [1,5,6,10]이면 1과 10 
            int dist_range = weak[i];
            int end = weak[i+w_size-1];
            
            for(int j=0; j<dist.size(); ++j) {
                dist_range += dist[j]; // j번째 친구가 커버하는 영역
                
                // 모든 지점 점검 마쳤을 경우
                // 즉, (1) 에서 10번 취약점까지 다 커버한 경우
                if(dist_range >= end) { 
                // 2개에서 커버가 끝날 수 있음 
                    answer = min(answer, j+1);
                    break;
                }
                //(3)
                // 외벽 점검을 마치지 않았지만 더이상 이동할 수 없으면 다음 지점으로 이동
                //dist j번째 친구로 커버할 수 없는 지점 찾아서 영역 바꿔주기
                // ex) start = 5, weak [1,3,5,6,10] . 6부터 커버 할 수 없음
                // -> start = weak[3]
                for(int z=i+1; z<i+w_size; ++z) { //시작위치가 i
                    if(weak[z] > dist_range) {
                        dist_range = weak[z];
                        break;
                    }
                }
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 1e8) return -1;
    
    return answer;
}