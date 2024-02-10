#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<bool>visit(10000);
vector<vector<string>> tickets;
vector<string> answer;
int t_size;
bool is_get_answer;
void dfs(string cur, int depth){
    
    if(is_get_answer)
            return;
    if(t_size == depth){
        
        is_get_answer=true;
    }
    for(int i=0;i<t_size;i++){
        if(!visit[i] && tickets[i][0]==cur){
            answer.push_back(tickets[i][1]);
            visit[i]=true;
            dfs(tickets[i][1],depth+1);
            if(!is_get_answer)
            {    answer.pop_back();
                visit[i]=false;
            }
        }
    }
}
bool cmp(vector<string> a, vector<string> b){
   return a[1]<b[1];
}

vector<string> solution(vector<vector<string>> _tickets) {
    tickets = _tickets;
    t_size = tickets.size();
    sort(tickets.begin(),tickets.end(),cmp);
    answer.push_back("ICN");
    dfs("ICN",0);
    return answer;
}