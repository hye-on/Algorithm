#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin>>n;

    long tmp=0;
    vector<long>p;
    vector<long>m;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp>0)
            p.push_back(tmp);
        else
            m.push_back(tmp); //0은 m에 들어가는 것이 좋다.
    }
    if(p.size()%2==1){
        p.push_back(0);
    }

    sort(p.rbegin(),p.rend());
    sort(m.begin(),m.end());
    
    long long ans=0;
    for(int i=0;i<p.size();i+=2){
        ans+= max(p[i]*p[i+1],p[i]+p[i+1]);
    }

    for(int i=0;i<m.size();i+=2){
        if(i==m.size()-1 && m.size()%2==1){
            ans+=m[i];
            continue;
        }
        ans+= max(m[i]*m[i+1],m[i]+m[i+1]);
    }

    cout<<ans;
    
    return 0;
}