#include <string>
#include <vector>
#include <set>
using namespace std;
set<int>s;
int solution(vector<int> elements) {
    int answer = 0;
    int sizeE = elements.size();
    int sum=0;
    for(int i=1;i<=sizeE;i++){//창 사이즈
        for(int j=0;j<sizeE;j++){
            sum=0;
            for(int k = j;k< j+i;k++ ){
                
                sum+=elements[k%sizeE];
            }
             s.insert(sum);
        }
       
        
    }
    
    return answer = s.size();
}