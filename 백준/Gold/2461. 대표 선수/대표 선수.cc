#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
//정렬, 슬라이딩 윈도우

//현재 세었는지 확인하기
long visit[1001];
long cnt;

int main() {
    cin>>n>>m;
    vector<pair<long,long>>v;
    int tmp=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tmp;
            v.push_back({tmp,i});
        }
    }

    int cnt=0;
    int idx=0;
    long num = 1000000001;
    long long ans=0;
    sort(v.begin(),v.end());
   
    
    for(int i=0;i<n*m;i++){
        long s  = v[i].first;
        long f = v[i].second;
        //포함되었으면 다음
        if(visit[f]>0){
            visit[f]++;
            continue;
        }
       
        cnt++;
        visit[f]++;
       
        //n개가 되었으면 답 갱신
        if(cnt==n){
            
            long cost = s - v[idx].first;
            if(cost<num){
               
                num = cost;
                ans = 1;
                
            }else if(cost==num){
                ans++;
            }

          
            
            visit[v[idx].second]--;
            if(visit[v[idx].second]==0){
                cnt--;
            }
            idx++;
                        
        }
      
        if(cnt<n)
            continue;
        
        while(visit[v[idx].second]-1 > 0){
            visit[v[idx].second]--;
            idx++;
        }
       
        long cost = s - v[idx].first;
        if(cost<num){
            
            num = cost;
            ans = 1;
           
        }else if(cost==num){
                ans++;
        }
         visit[v[idx].second]--;
        if(visit[v[idx].second]==0){
                cnt--;
        }
        idx++;
        
        
    }

    cout<<num;
    
    return 0;
}