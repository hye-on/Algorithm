#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int>a,vector<int>b ){
    if(a[1]<b[1])
        return true;
    else if(a[1]==b[1])
        return a[0]<b[0];
    else
        return false;
        
}
int solution(vector<vector<int>> routes) {
    int answer = 1;
    //진출 지점으로  오름차순 정렬
    sort(routes.begin(),routes.end(),cmp);
    int routes_size = routes.size();
    //카메라가 차의 이동경로에 포함되는지 검사 
    int camera_point = routes[0][1], next_routes_begin = 0,next_routes_end;
    for(int i = 1;i<routes_size;i++){
        next_routes_begin = routes[i][0];
        next_routes_end = routes[i][1];
       if( next_routes_begin > camera_point ){
           answer++;
           camera_point = next_routes_end;
           
       }        
    }
    return answer;
}