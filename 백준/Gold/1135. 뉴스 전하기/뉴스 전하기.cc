#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//dp

// 자식 들 중 누가한테 먼저 전화를 돌려야할까? 순열? x
// 자식 들 중 제일 오래 걸리는 자식한테 먼저 전화 돌리기. 나머지는 몇분 걸렸는지 중요x
// 답은 자식 들 중 제일 오래 걸리는 시간 + 자식 개수

//11:00

int n;
vector<int>edges[50];
int dp[50];
int findNewsTime(int cur){

    if(edges[cur].size()==0)
        return dp[cur]=0;
    
  
   
    vector<int>child_time;
    for(auto node: edges[cur]){
         child_time.push_back(findNewsTime(node));
    }

    sort(child_time.rbegin(),child_time.rend());
    int ret =0;
   
    // 자식들 전화받는 시각 + 자기 자식들에게 전화하는 시간
    for (int i = 0; i < child_time.size(); i++){
        ret = max(ret, child_time[i] + i + 1);
    }
    
    
    return dp[cur]= ret;
}
int main() {

    cin>>n;

    int parent=0;
    for(int i=0;i<n;i++){
        cin>>parent;
        if(parent==-1)
            continue;
        edges[parent].push_back(i);
    }

    
    cout<<findNewsTime(0);
    
    
    return 0;
}