#include <string>
#include <vector>

using namespace std;
int num[100001];
int solution(int n) {
    int answer = 0;
    num[2] =1;
    num[1] = 1;
    for(int i=3;i<=n;i++){
        num[i] =(num[i-1]+num[i-2])%1234567;
    }
    
    return answer = num[n];
}