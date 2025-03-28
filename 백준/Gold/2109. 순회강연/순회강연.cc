#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<pair<int,int>>pq;
priority_queue<int>store;
int n,p,d;

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        
        cin>>p>>d;
        pq.push({d,p});
    }

    if(n==0){
        cout<<0;
        return 0;
    }
    int day =pq.top().first;
    int answer=0;
    int max_n =0;
    while(day>0){

        max_n=0;
       
        while(!pq.empty() && pq.top().first>=day){
            store.push(pq.top().second);
            pq.pop();
        }
      
        day--;
        if(!store.empty()){
            answer+=store.top();
            store.pop();
        }
       
    }

    cout<<answer;
    
    return 0;
}