#include <string>
#include <vector>
#include<stack>
using namespace std;

stack<int>s;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size());
    for(int i=numbers.size()-1;i>=0;i--){
        
        while(!s.empty()){
            if(s.top()>numbers[i]){
                answer[i]=s.top();
                break;
            }else{
                s.pop();
            }
        }
        if(answer[i]==0)
            answer[i]=-1;
        s.push(numbers[i]);
        
    }
    return answer;
}