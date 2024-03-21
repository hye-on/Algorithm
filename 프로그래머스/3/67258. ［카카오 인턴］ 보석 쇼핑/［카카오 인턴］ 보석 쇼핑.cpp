#include <string>
#include <vector>
#include <map>
#include<iostream>
#include<set>
using namespace std;

map<string,int>m;
set<string>s;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    for(int i=0;i<gems.size();i++){
        s.insert(gems[i]);
    }
    int kind = s.size();
    int cur_kind =0;
    int start=0,end=0;
    int ansS=0,ansE=gems.size();
    while(1){
    //다 포함했다면  
    //start를 증가하면서 취소범위 구하기
    //최소 범위 갱신
    if(cur_kind == kind){
        
        while(1){
            //2개 이상 있으면 줄여도 됨
            if(m[gems[start]]>1){
                m[gems[start]]--;
                start++;
            }
            else
                break;
        }
        if(end-start<ansE-ansS){
            ansE=end;
            ansS=start;
        }
       if(m[gems[start]]<=1)
           cur_kind--;
        m[gems[start]]--;
        start++;
        
    }
    //다 포함안했다면 
    //다 포함할때까지 end 증가
    else{
        //종류 추가
        if(end==gems.size())
            break;
        if(m[gems[end]]==0){
            cur_kind++;
        }
        //개수 세주기
        m[gems[end]]++;
        end++;
    }
    
        
    }
    return answer={ansS+1,ansE};
}