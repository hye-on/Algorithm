#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    long long l = distance;
    long long r = 0;
    long long mid = 0 ;
    
    sort(rocks.begin(),rocks.end());
    rocks.insert(rocks.begin() + 0,0);
    rocks.insert(rocks.end(),distance);

   while(r<=l){
    int removeN = n;
       mid = (l+r)/2; // 거리의 최솟값
     //  cout<<r<<"  "<<l<<endl;
       int idx =0;
       for(int i=1;i<rocks.size();i++){
            if(rocks[i]-rocks[idx]<mid){
                removeN--;
            }else{
                idx= i;
            }
           if(removeN<0)
               break;
        }
       if(removeN<0){
           //최솟값을 줄여줘야 함
           l = mid-1;

       }else{
          //최솟값을 늘려도 됨
           r=mid+1;
           answer=mid;
          
       }
   }
    return answer;
}