#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int idx=0;
    int sum=0;
    int ansS=0,ansE=sequence.size()-1;
    for(int i=0;i<sequence.size();i++){
        sum+=sequence[i];
        if(sum==k){
            if(i-idx<ansE-ansS){
                ansS = idx;
                ansE = i;
            }
        }
        while(idx<i && sum>k){
            sum-=sequence[idx];
            idx++;
        }
        if(sum==k){
            if(i-idx<ansE-ansS){
                ansS = idx;
                ansE = i;
            }
        }
    }
    answer.push_back({ansS});
    answer.push_back({ansE});
    return answer;
}