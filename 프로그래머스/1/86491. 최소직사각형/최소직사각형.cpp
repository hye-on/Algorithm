#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>ww;
vector<int>hh;

int s1,s2;
int w,h;
int solution(vector<vector<int>> sizes) {
    int answer = 0;


    for(auto card : sizes){
        if(card[0]>card[1]){
            ww.push_back(card[0]);
            hh.push_back(card[1]);
        }
        else{
            ww.push_back(card[1]);
            hh.push_back(card[0]);
        }
    }
    
    sort(ww.begin(),ww.end(),greater<>());
    sort(hh.begin(),hh.end(),greater<>());
    
    w=ww[0];
    h=hh[0];
    
    return answer = w*h ;
}