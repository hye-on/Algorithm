#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<bool>visit(1001);
vector<bool>my(1001);
int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
   
    int pair=0, st_pair=0;
    // 1개를 뽑아서 pair를 만들 수 있다면 구매
    // 2개를 뽑아서 pair를 만들 수 있다면 보관
    // 아직 다른 짝이 나오지 않았다면 나왔다는 표시만 해준다.
    
    
     // n/3장 가진다. 
    for(int i=0;i<n/3;i++){
        if(visit[n+1-cards[i]])
            pair++;
        
        visit[cards[i]]=true;
        my[cards[i]]=true;
      
    }
   
    for(int i=n/3;i<n;i+=2){
        int c1 = cards[i];
        int c2 = cards[i+1];
        
        if(coin>0 && my[n+1-c1]){
           
            coin--;
            pair++;
        }else if(visit[n+1-c1]){
             st_pair++;
        }
        visit[c1]=true;
        if(coin>0 && my[n+1-c2]){
          
            coin--;
            pair++;
        }else if(visit[n+1-c2]){
           st_pair++;
         }
       
        
        // if(c1+c2==(n+1))
        //     st_pair++;  
        //  }
        
        visit[c2]=true;
        
        if(pair>0){
            answer++;
            pair--;
        }else if(coin>=2 && st_pair>0){
            answer++;
            coin-=2;
            st_pair--;
        }else
            break;
        
    }    
   
    
    
    return answer;
}