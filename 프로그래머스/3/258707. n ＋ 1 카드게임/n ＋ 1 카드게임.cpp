#include <string>
#include <vector>
#include<iostream>
using namespace std;
//1:14  ~ 2:59 = 1시간 45분
//처음 세팅


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
        }//앞에 나왔던 것까지 같이 산다면 패스할 수 있음 -> 후보로 등록
        else if(coin> 1 &&st[n+1 - p1]){ 
            k2++;
        }
         
        if(coin >0 && num[n+1 - p2])
        {   
            coin--;
            num[p2]=false;
            num[n+1-p2] = false;
            k++;
        }
        else if(coin> 1 &&st[n+1 - p2]){     
            k2++;
        }
        
        //앞에 나왔던 것들을 표시
        st[p1]=true;
        st[p2]=true;
        
        //뽑은 2개끼리 n+1이 될 수 있다면 후보로 표시
        if(coin>1 &&(p1+p2)== (n+1) ){
            k2++;
        }
            
        if(k>0){
            //가지고 있던 짝(n+1) 씀        
            k--; 
            r++;
            
        }else if(coin>1 && k2>0){ //없다면 가능한후보 씀. 그리고 coin-=2
            k2--;
            coin-=2;
            r++;
        }
        else{
            //라운드 진행못하면 끝
            break;
        }

        
    }
    return answer = r;
}
