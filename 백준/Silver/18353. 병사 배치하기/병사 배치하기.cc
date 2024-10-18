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
        int idx = a.size()-1;
        while(idx>=0){
            if(a[idx]>t){
                a[idx+1]=t;
                break;
            }
            idx--;
        }

        if (idx == -1) {
            a[0] = t;
        }
    }
    cout<<n-a.size();
    return 0;
}