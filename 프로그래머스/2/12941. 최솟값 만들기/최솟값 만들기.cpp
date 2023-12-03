#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int arr_size = A.size();
    for(int i = 0; i< arr_size;i++){
        answer+= A[i] * B[arr_size-i-1];
    }
    
   

    return answer;
}