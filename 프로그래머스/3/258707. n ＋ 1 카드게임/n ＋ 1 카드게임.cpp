#include <string>
#include <vector>
#include<iostream>
using namespace std;
//1:14
//처음 세팅
//두장씩 뽑기 - 코인 쓰고 가져가기 or 버리기
//n+1 만들면 다음 라운드 

// 1 2 3 4 5 6 7 8 9 10 11 12 13
// 짝이 정해져 있다.

bool num[1001];
bool st[1001];

int p1,p2;
bool nocard=false;
int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    // n/3은 초기에 가지고 있음 
    int k=0,k2=0;
    for(int i=0;i<n/3;i++){
        if(num[n+1 - cards[i]])
            k++;
        num[cards[i]] = true;
    }
   
    int r=1;

    for(int i=n/3;i<cards.size();i+=2){
        p1 = cards[i];
        p2 = cards[i+1];
        
        //만약에 n + 1만들 수 있으면 사기
        if(coin>0 && num[n+1 - p1])
        {   
            
            coin--;
            num[p1]=false;
            num[n+1-p1] = false;
            k++;
        }else if(coin> 1 &&st[n+1 - p1]){
            k2++;
        }
         
        if(coin >0 && num[n+1 - p2])
        {   
            coin--;
            num[p2]=false;
            num[n+1-p2] = false;
            //라운드 끝
            k++;
            //cout<<p2<<endl;
        }else if(coin> 1 &&st[n+1 - p2]){
            
            k2++;
        }
        st[p1]=true;
        st[p2]=true;
        if(coin>1 &&(p1+p2)== (n+1) ){
            k2++;
        }
        
      
        if(k>0){
            //가지고 있던 짝 씀
            
            k--;
            r++;
            
        }else if(coin>1 && k2>0){
            k2--;
            coin-=2;
            r++;
        }
        else{
            if(i!=n-2)
                break;
            if(nocard==true)
                break;
            nocard=true;
        }

        
    }
    return answer = r;
}