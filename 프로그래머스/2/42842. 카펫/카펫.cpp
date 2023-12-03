#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    for(int i =1 ;i*i<=yellow; i++){
        if(total%(i+2))
            continue;
       if (!(yellow%i) &&yellow/i==total/(i+2)-2 ){
            answer.push_back(total/(i+2));
            answer.push_back(i+2);
       }
     
        
    }
    return answer;
}