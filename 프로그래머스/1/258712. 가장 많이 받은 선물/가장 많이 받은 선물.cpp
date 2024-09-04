#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int cnt[51]; //선물 지수 
map<string,int>idx; //이름 인덱스
int num[51][51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    string gh = "";
    for(int i=0;i<friends.size();i++){
        idx[friends[i]] = i;
    }
    
    for(int i=0;i<gifts.size();i++){
        gh = gifts[i];
        int spilt_idx = gh.find(' ');
        
        string a = gh.substr(0,spilt_idx); // 선물 준 사람
        string b  = gh.substr(spilt_idx+1); //선물 받은 사람
        
        int a_idx = idx[a];
        int b_idx = idx[b];
        
        num[a_idx][b_idx]++;
        cnt[a_idx]++;
        cnt[b_idx]--;
    }
    int nCnt=0;
    for(int i=0;i<friends.size();i++){
        nCnt=0;
        for(int j=0;j<friends.size();j++){
            if(i==j)
                continue;
            if(num[i][j]>num[j][i])
                nCnt++;
            else if(num[i][j]==num[j][i]){
                if(cnt[i]>cnt[j])
                    nCnt++;
            }
        } 
        answer = max(answer, nCnt);
    }
    
   
    return answer;
}