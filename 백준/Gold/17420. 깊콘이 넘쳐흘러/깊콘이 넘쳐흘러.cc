#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//3:?

// 100000 * 10억/30 (3000) * 

int n;
priority_queue<pair<long,long>>pq; 
vector<pair<long,long>>num;

int main() {
    cin>>n;
    num.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>num[i].second; //남은시간
        num[i].second *=-1; 
    }
    for(int i=0;i<n;i++){
        cin>>num[i].first; //써야 하는 시간 
        num[i].first *=-1;
    }
    for(int i=0;i<n;i++){
        pq.push(num[i]);
    }

    long multi =0;
    long ans=0;
    long cur_time=0;
    long time_idx =0;
    long min_time =-1;
    long max_time =0;
    
    while(!pq.empty()){
        long t = - pq.top().first;
        long rest_time = -pq.top().second;
        pq.pop();
       
        //남아있는 시간이 제일 작은 것부터 써야 한다.
        //지금까지 썼던 시간보다 더 커야된다. 
        // i  i+1  i+2
        // 30 50    20(이게 50보다 커야 해서 더해주는과정)
        multi=0;
        if(rest_time<min_time){
            multi = (min_time-rest_time)/30;
            if((min_time-rest_time)%30>0)
                multi++;
            rest_time+=30*multi;
            
        }

        ans+=multi;
        multi=0;

        //사용할 계획인 시간보다 커야 한다.
        if(t>rest_time){
            multi = (t-rest_time)/30;
            if((t-rest_time)%30>0)
                multi++;
            rest_time+=30*multi;
        }

        max_time = max(max_time,rest_time);    
        if(!pq.empty() && t<-pq.top().first){
            min_time = max(min_time,max_time);
        }
        
        ans+=multi;
       
      
    }

    cout<<ans;
    
    return 0;
}