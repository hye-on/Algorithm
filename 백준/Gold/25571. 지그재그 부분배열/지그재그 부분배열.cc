#include <iostream>

using namespace std;

//문제가 어렵지만 결국 업다운 하는 경우의수 구하기
// for 문으로 모든 경우의 수를 구하면 시간 초과 날 것암
// 연속으로 업다운 길이 구하면 만약 4 이면  3 2 1  O(N)의 시간 복잡도

int T;
int n;
int num[100002];
//1000000000
long ans;
void cal(int idx,bool isUp,long cnt){ //up 해야 하는 차례인지
   
    if(idx==n+1){
        if(cnt>=1){
            ans += (1+cnt)*cnt/2;
            
        }
        return;
    }
    bool isZig = false;
    
    if(isUp){
        if(num[idx-1]<num[idx]){
            cnt++;
            isZig = true;
        }
    }else{
        if(num[idx-1]>num[idx]){
            cnt++;
            isZig = true;
        }
    }
    
    
    //경우의 수 계산  1 2 3 4  4*5/2
    if(!isZig ){
        if(cnt>=1){
           
             ans += (1+cnt)*cnt/2;
        }
        cnt=0;
    }
    cal(idx+1,!isUp,cnt);
}
int main() {

    cin>>T;
    
    while(T--){
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>num[i];
        }
       
        num[0] = 1000000001;
        cal(1,true,0); // 3 1 3 1 3
        num[0] = 1000000001 *-1;
        cal(1,false,0); // 1 3 1 3 1
        cout<<ans<<'\n';
        ans=0;
    }
    
    return 0;
}