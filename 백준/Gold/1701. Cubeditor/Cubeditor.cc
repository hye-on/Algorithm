#include <iostream>
#include <vector>
#include<string>

using namespace std;

vector<int> getPi(string p){
    vector<int> pi(p.size());
    for(int i=1,j=0;i<p.size();i++){
        while(j>0 && p[i]!=p[j])
            j=pi[j-1];
        if(p[i]==p[j])
            pi[i] = ++j;
    }
    return pi;
}

int main() {

    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        vector<int>pi = getPi(s.substr(i));
        for(int j=0;j<s.size()-i;j++){
            if(pi[j]>ans)
                ans = pi[j];
        }
    }
    cout<<ans;
    return 0;
}