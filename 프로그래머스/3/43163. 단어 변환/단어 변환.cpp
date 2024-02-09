#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int words_len;
vector<int>cnnt_node[51];
bool visit[51];
int dist[51];
int ans_idx;
vector<string> words;
int answer;
int begin_size;
int countSameChar(string a,string b){
    int num=0;
    for(int k=0;k<a.size();k++){
        if(a[k]==b[k])
            num++;
    }
   
    return num;
}
void bfs(int node){
    queue<int>q;
    q.push(node);
    visit[node]=true;
    while(!q.empty()){
        int current_idx = q.front();
        q.pop();
        if(current_idx==ans_idx){
            answer=dist[current_idx];
            break;
        }
        for(int i=0;i<cnnt_node[current_idx].size();i++){
           
            if(visit[cnnt_node[current_idx][i]])
                continue;
            q.push(cnnt_node[current_idx][i]);
            visit[cnnt_node[current_idx][i]] = true;
            dist[cnnt_node[current_idx][i]]=dist[current_idx]+1;
            
        }
    }
}
int solution(string begin, string target, vector<string> _words) {
    words=_words;
    words.push_back(begin);
    words_len = words.size();
    begin_size = begin.size();
    for(int i=0;i<words_len;i++){
        for(int j=i+1;j<words_len;j++){
            
            
            if(i==j){
                
                continue;
                
            }
          
            
            if(countSameChar(words[i],words[j])==(begin_size-1)){
               
                cnnt_node[i].push_back(j);
                cnnt_node[j].push_back(i);
            }
           
        }
    }
    
    bool is_exist_ans=false;
    for(int i=0;i<words_len-1;i++){
        if(target==words[i]){
            is_exist_ans=true;
            ans_idx=i;
        }
    } 
    if(!is_exist_ans)
        return answer=0;
   
   // for(int i=0;i<words.size();i++)
   //     for(int j=0;j<cnnt_node[i].size();j++){
   //         cout<<words[i]<<"  "<<words[cnnt_node[i][j]]<<endl;
   //     }
   // cout<<"여기"<<endl;
    bfs(words_len-1);
    return answer;
}