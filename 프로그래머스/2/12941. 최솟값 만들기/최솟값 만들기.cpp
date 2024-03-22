#include <iostream>
#include<vector>
#include<queue>
using namespace std;


int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    priority_queue<int>a(A.begin(),A.end());
    priority_queue<int,vector<int>,greater<int>>b(B.begin(),B.end());
    while(!a.empty()){
        answer+=(a.top()*b.top());
        a.pop();b.pop();
    }


    return answer;
}