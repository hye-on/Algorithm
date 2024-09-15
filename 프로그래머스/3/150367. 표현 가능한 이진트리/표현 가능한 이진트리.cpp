#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long total;
long long depth=0;
string testS;
long long ans;
//2~2:45 - 이어서 풀기
string numberTo01(long long num){
    string tmp="";
    while(num>0){
        if(num%2==1)
            tmp ='1'+tmp;
        else
            tmp= '0' + tmp;
        num/=2;
    }
    return tmp;
}
long long findDepth(int n){
    int n2=1;
    int d=0;
    int tt=0;
    while(n>0){
        n-=n2;
        tt+=n2;
        n2*=2;   
        d++;
    }
    total= tt;
    return d;
}
bool isAllDummy(int start, int end) {
    for (int i = start; i <end; i++) {
        if (testS[i] == '1') {
            return false;  
        }
    }
    return true;  
}
//idx위치는 1이어야 한다. depth가 1일 때 제외
void tree(long long start,long long end, long long depth){
    int idx = (start+end)/2;
   
    if(testS[idx]=='0' && depth!=1){
        if (!isAllDummy(start, end)) {
          
            ans = 0;  // 더미 노드 아래에 1인 노드가 있으면 오답 처리
        }
    }
    if(depth==1)
        return;
    
    tree(start,idx,depth-1);    
    tree(idx+1,end,depth-1);    
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size();i++){
        testS = numberTo01(numbers[i]);
        depth = findDepth(testS.size());
        while(testS.size()<total)
            testS = '0' + testS;
        ans=1;
        tree(0,total,depth);
        answer.push_back(ans);

        
    }
    return answer;
}