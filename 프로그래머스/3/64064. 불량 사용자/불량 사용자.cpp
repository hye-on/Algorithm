#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;

bool visit[9];
vector<int>num[9];
int end_i;
vector<string>v;
set<string>ans;
void backtracking(string s, int depth){
    //cout<<"d "<<s<<endl;

    if(depth==end_i){
        sort(s.begin(),s.end());
        
        ans.insert(s);
        return;
    }
    for(int i=0;i<num[depth].size();i++){
        if(!visit[num[depth][i]]){
            visit[num[depth][i]]=true;
            backtracking(s+to_string(num[depth][i]),depth+1);
            visit[num[depth][i]]=false;
        }
    }
    
}
int solution(vector<string> user_id, vector<string> banned_id) {
    
    int answer = 1;
    int user_size = user_id.size();
    int banned_size = banned_id.size();
    end_i = banned_size;
   int cnt=0;
    bool chk=false;
    for(int i=0;i<banned_size;i++){
        cnt=0;
        for(int j=0;j<user_size;j++){
            if(banned_id[i].size() == user_id[j].size()){
                for(int k=0;k<banned_id[i].size();k++){
                    if(banned_id[i][k]=='*')
                        continue;
                    if(banned_id[i][k]!=user_id[j][k]){
                        chk=true;
                        break;
                        
                    }
                }
                if(!chk){
                    num[i].push_back(j);
                   
                }
                chk=false;
            }
            
        }
        answer*=cnt;
    }
    
    backtracking("",0);
    // for(auto s :ans)
    //     cout<<s<<endl;
   // cout<<endl;
   // cout<<ans.size()<<endl;
    answer= ans.size();
    return answer;
}