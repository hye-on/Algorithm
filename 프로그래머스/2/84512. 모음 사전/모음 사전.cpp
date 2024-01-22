#include <string>
#include <vector>

using namespace std;
string end_s;
int chk[5];
string alphabet = "AEIOU";
int answer ;
int cnt;

void dfs(string s){
   
    if(s==end_s)
    {
        answer=cnt;
        return;
    }
    if(s.size()>4)
        return;
    for(int i=0;i<5;i++){
        cnt++;
        dfs(s+alphabet[i]);
    }
}
int solution(string word) {
    end_s=word;
    dfs("");
    return answer;
}