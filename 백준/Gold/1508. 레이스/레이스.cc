#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//2:00~
//매개변수 탐색 - 이분탐색

int n,m,k;
int main() {
    cin>>n>>m>>k; //k개 구간 중 m 명 배치
    vector<int>point(k);
    
    // 모든 간격이 r보다 크게 하기, 이분탐색으로 최대의 r 찾기

    string array = "";
    string ans="";
    for(int i=0;i<k;i++){
        cin>>point[i];
        array+='0';
    }
    
    int left = -1, right = n+1,mid=0;
    while(left+1<right){
        
        mid = (left+right)/2;
        int cnt =1;
       
        int idx=0;
        int range=0;
        
         //간격이 최소 m이상이어야 함
        string tmp=array;
        tmp[0]='1';
        for(int i=0;i<k;i++){
            range = point[i]-point[idx];
            
            if(range>=mid){
                cnt++;
                //이 조건 빼먹음
                if(cnt<=m)
                    tmp[i]='1';
                idx=i;
                range=0;           
                
            }
        }
   
        //m명 비교
        if(cnt>=m){ //간격을 늘려야 함
            left = mid;
            ans = tmp;
        }else{
            
            right = mid;
        }
    }

    cout<<ans;
    
    return 0;
}