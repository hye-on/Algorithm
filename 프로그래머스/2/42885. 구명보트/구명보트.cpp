#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    
    int people_size = people.size();
    int idx1=0;
    int idx2=people.size()-1;
    int s_i=0;
    
    while(true){
        if(idx1>=idx2)
            break;
        if(people[idx2]+people[idx1]<=limit){
            people[idx2]+=people[idx1];
            idx1++;
            idx2--;
        }
        else{
            idx2--;
        }
    }
    
    answer=people.size()-idx1;
    return answer;
}