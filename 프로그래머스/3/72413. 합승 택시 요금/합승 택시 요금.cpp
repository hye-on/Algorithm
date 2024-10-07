#include <string>
#include <vector>

using namespace std;

#define MAX 1e7


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    vector<vector<int>> cost(n+1, vector<int>(n+1, MAX));
    
    for(int i=1; i<=n; ++i) cost[i][i] = 0;
    
    for(auto fare: fares) {
        cost[fare[0]][fare[1]] = fare[2];
        cost[fare[1]][fare[0]] = fare[2];
    }
    
    
    for(int k=1; k<=n; ++k) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    
    for(int i=1; i<=n; ++i) {
    	
        int total = cost[s][i] + cost[i][a] + cost[i][b];
        
        answer = min(answer, total);
    }
    
    return answer;
}