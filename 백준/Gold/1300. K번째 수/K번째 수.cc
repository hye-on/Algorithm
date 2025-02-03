#include <iostream>

using namespace std;

//1000000000 10억
//i*j에서 
// 1 2 3 4 5  6  7  8  9  10
// 2 4 6 8 10 12 14 16 18 20
// 3 6 9 12
// 3*3-> 9
//9 미만인게 2개, 4개 8개,, -> 등비수열,, 공식 기억이 안나
//나머지로 개수 구했던 것 같다

//NOTE: 정렬되어 있으면 이분탐색 떠올리기
//n보다 작은거 개수 구할때 나누기 해서 몫을 활용할 수 있음
//i열보다 큰 열에도 더 큰수가 있을 수 있음
long long n, k, ans;

int main() {

    cin>>n;
    cin>>k;

    long  left=0,right=n*n+1,mid=0;
    int t=0;
    long long ans=0;
    while(left+1<right){
        mid = (left+right)/2;

        long sum=0;
       for(int i=1;i<=n;i++){
           t = mid /i > n ? n : mid/i;
           if(t==0)
               break;
           sum+=t;
       }

        if(sum<k){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout<<right;
    
    return 0;
}