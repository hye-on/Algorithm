#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>s){
        answer.push_back(-1);
        return answer;
    }
    int num = s/n;
    int nn=n;
    int cnt = n-s%n;
    int div_n = s/nn;
    for(int i=0;i<n;i++){
        if(i<cnt)
            answer.push_back(div_n);
        else{
            answer.push_back(div_n+1);
        }
            
    }
    return answer;
}