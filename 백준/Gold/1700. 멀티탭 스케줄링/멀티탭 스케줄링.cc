#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
//10:24 ~11:06
int n,k;
int num[101];
 vector<int>selectN;
int re_idx; //selectN에서 교체할 자리
int dis; //제일 멀리있는 애 거라

void findIdx(int i){
    
     for(int j=0;j<n;j++){ 
        for(int kk = i+1;kk<k;kk++){
            if(num[kk]==selectN[j]){
                if(dis<kk){
                    dis = kk;
                    re_idx= j;
                }
               break;
            }
            //끝까지 안나오면 얘로 교체
             if(kk==k-1){
                re_idx = j;
                 return;
            }
        }       
    }
}

int main() {
    cin>>n>>k;

    if(n>=k){
        cout<<0;
        return 0;
    }
   
    selectN.resize(n);
    
    for(int i=0;i<k;i++)
        cin>>num[i];

    int ans=0;
    int cnt=0;
    int start_idx=0;
    for(int i=0;i<n;i++){
        //없을 경우 넣어줌
        if(find(selectN.begin(),selectN.end(),num[start_idx])==selectN.end()){
            selectN[i] =num[start_idx];
            cnt++;
        }else
            i--;
        start_idx++;
        if(cnt==n)
            break;
        
    }
        
    
   
    for(int i=start_idx;i<k;i++){
       
        //이미 있어서 교체 안함 
        if(find(selectN.begin(),selectN.end(), num[i])!=selectN.end())
            continue;  
        
        //맨 마지막은 안찾고 그냥 교체
        if(i==k-1){
            ans++;
            continue;
        }
        //하나씩 돌면서 제일 멀리있는 것 교체
        re_idx = -1;
        dis=0;
        //교체할 자리 찾기
        findIdx(i);
        
         //교체 
        selectN[re_idx] = num[i];
        ans++;
        
    }

    cout<<ans;
    return 0;
}