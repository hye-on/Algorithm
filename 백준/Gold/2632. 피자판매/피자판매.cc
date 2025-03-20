#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int size_p, a, b;
    cin >> size_p >> a >> b;
    
    vector<int> ap(a);
    vector<int> bp(b);
    
    for(int i = 0; i < a; i++) {
        cin >> ap[i];
    }
    
    for(int i = 0; i < b; i++) {
        cin >> bp[i];
    }
    
    // A 피자의 모든 가능한 합 생성
    vector<int> a_sums;
    a_sums.push_back(0);
    

    int total_a = 0;
    for(int i = 0; i < a; i++) {
        total_a += ap[i];
    }
    
 
    if(total_a <= size_p) {
        a_sums.push_back(total_a);
    }
    
  
    for(int start = 0; start < a; start++) {
        int sum = 0;
        for(int length = 1; length < a; length++) {
            int idx = (start + length - 1) % a;
            sum += ap[idx];
            if(sum <= size_p) {
                a_sums.push_back(sum);
            }
        }
    }
    
   
    vector<int> b_sums;
    b_sums.push_back(0); 
    

    int total_b = 0;
    for(int i = 0; i < b; i++) {
        total_b += bp[i];
    }

    if(total_b <= size_p) {
        b_sums.push_back(total_b);
    }
    

    for(int start = 0; start < b; start++) {
        int sum = 0;
        for(int length = 1; length < b; length++) {
            int idx = (start + length - 1) % b;
            sum += bp[idx];
            if(sum <= size_p) {
                b_sums.push_back(sum);
            }
        }
    }
    

    sort(a_sums.begin(), a_sums.end());
    sort(b_sums.begin(), b_sums.end());
    
  
    long long answer = 0;
    
    for(int a_sum : a_sums) {
        int target = size_p - a_sum;
        if(target < 0) continue;
        
      
        answer += upper_bound(b_sums.begin(), b_sums.end(), target) - 
                 lower_bound(b_sums.begin(), b_sums.end(), target);
    }
    
    cout << answer << endl;
    
    return 0;
}