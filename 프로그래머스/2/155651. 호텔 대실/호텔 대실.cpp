#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int,int>>book;
int room[1001];
priority_queue<int>q;

int c(string t){
    int tmp = (t[0]-'0') * 600 + (t[1]-'0') * 60 + (t[3]-'0')*10 + t[4]-'0';
    return tmp;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(int i=0;i<book_time.size();i++){
        book.push_back({c(book_time[i][0]),c(book_time[i][1])+10});
    }
    sort(book.begin(),book.end());
                       
    for(int i=0;i<book.size();i++){
        //집어 넣을 수 있다면
        if(!q.empty() && -q.top()<= book[i].first){
            q.pop();
        }
        
        q.push(-book[i].second);
    }
    return q.size();
}