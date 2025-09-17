#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 5:38
//초기화 n/3 장
// 카드 2장 뽑기
// 카드는 돈내고 가지거나 버리거나
// n+1 카드 내야함 -> 못내면 죽음 

// 카드를 사서 1쌍이될 수 있으면 바로 삼
// 못사면 "살수 있었던 카드리스트(a)에 넣어둠"
// 카드를 사서 a에 있는 카드랑 같이 한쌍이 될 수 있다면
  //아직은 사지 말고 후보에 넣어둠 -> 나중에 낼 카드가 없고 코인이 남아있을 때 구매

// 현재 낼 수 있는 카드쌍 + 구매하면 낼 수 있는 카드쌍 변수 2개 필요

int n;
int card_pair, pos_card_pair;
vector<int>card_status; // 0: 아직 안나옴, 1:나옴 구매x, 2:나옴 구매o
vector<int> cards;
int coin;

void pick(int num){
  int cd_n = n+1-num;
  
  if(coin>0 && card_status[cd_n]==2){ //구매
        coin--;
        card_status[num] =2;
        card_pair++;
    }else if(card_status[cd_n]==0){ //카드 나온거 표시
        card_status[num] = 1;
    }else if(card_status[cd_n]==1){ //카드 나온거 표시 + 구매가능쌍 
        card_status[num] =1;
        pos_card_pair++;
    }
    
}

int solution(int _coin, vector<int> _cards) {
    int answer = 1;
    
    n = _cards.size();
    cards = _cards;
    coin = _coin;
    card_status.resize(n+1,0);
        
    // 초기화 하는 동안 카드쌍 세기
    for(int i=0;i<n/3;i++){
        card_status[cards[i]] =2;
        int cd_n = n+1-cards[i];
        if(card_status[cd_n]==2)
            card_pair++;
    }
    
  
    //게임
    for(int i=n/3;i<n;i+=2){
        int cd_n = n + 1 - cards[i];
       pick(cards[i]);
       pick(cards[i+1]); 
       
        if(card_pair==0){
            if(coin<2)
                break;
            else if(pos_card_pair>0){
                coin-=2;
                card_pair++;
                pos_card_pair--;
            }
        }
        if(card_pair==0)
            break;
        card_pair--;
        answer++;
    }
    return answer;
}