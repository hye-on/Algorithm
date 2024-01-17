#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(),citations.end(),greater<>());
    int size = citations.size();
    int h_index=0;
    for(int i= 0 ;i<size;i++){
        if(citations[i]>h_index)
            h_index++;

    }
    
    return answer=h_index;
}