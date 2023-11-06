#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int triangle_size = triangle.size();
    int triangle_c_size = triangle.size();
    for(int i=triangle_size-1;i>0;i--,triangle_c_size--){
        for(int j = 0;j<triangle_c_size-1; j++ ){
            triangle[i-1][j] = max(triangle[i][j],triangle[i][j+1]) + triangle[i-1][j];
        }
        
    }
    
    answer = triangle[0][0] ;
    return answer;
}