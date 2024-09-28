#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


//k점에 맞힌 선수가 k 점을 가져감. 같으면 어피치가 가져감
//종 점수가 같을 경우 어피치를 우승자로 결정
//라이언이 가장 큰 점수 차이로 우승할 수 있는 방법이 여러 가지 일 경우, 가장 낮은 점수를 더 //많이 맞힌 경우
//투 포인터?
int p[11];

int sum =55;
int mySum =0;

int maxS;
vector<int> ans(11);
vector<int> result(11);
vector<int> info;

void checkAns(vector<int>& num){
    int yourS =0;
    int myS =0;
    for(int i=0;i<11;i++){
        int score = 10-i;
        if(info[i]<num[i]){
            myS += score;
        }else if(info[i]>=num[i] && info[i]>=1){
            yourS+=score;
        }
    }
   
    if(myS>yourS){
        if(myS-yourS>maxS){ //가장 큰 점수 차이
            maxS = myS-yourS;
            ans = num;
        }else if(myS-yourS == maxS){
            for(int i=10;i>=0;i--){
                if(ans[i]>num[i])
                    return;
                else if(ans[i]<num[i]){
                    ans = num;
                    return;
                }
            }
        }
    }
}
void recursion(int depth,int rn ,vector<int>&num){

    if(rn<0){
        return;
    }
    if(depth==11){ //답이 될 수 있는지 체크
        if(rn>0)
            num[10] =rn;
        checkAns(num);
        return;
    }
    int t  = info[depth]+1;
    num[depth] = t;
    recursion(depth +1 ,rn-t , num); //과녁 맞춤
    num[depth] =0;
    recursion(depth +1 ,rn , num); // 과녁 못맞춤
    
}

vector<int> solution(int n, vector<int> _info) {
    vector<int> answer;
    info = _info;
    recursion(0,n,result);
    for(int i=0;i<11;i++)
        if(ans[i]>=1)
            return ans;
    answer.push_back(-1);
    return answer;
}