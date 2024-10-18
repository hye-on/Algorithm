#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int>a;
int ans,t;
int main() {
    cin>>n;
    
    for(int i=0;i<n;i++){
       cin>>t;
        
        if(i==0 || t<a.back()){
            a.push_back(t);
            continue;
        }
      
       auto it = lower_bound(a.begin(), a.end(), t, greater<int>());
            *it = t;

      
    }
    cout<<n-a.size();
    return 0;
}