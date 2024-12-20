#include <iostream>
#include<map>
#include<algorithm>

using namespace std;

map<string,int>m;

//4:47 ~5:11
//투포인터
string s="";
int cnt;
int ans;
int main() {
    
    cin>>s;
    for(int i=0;i<s.size()-ans;i++){          
        for(int j=i+1;j<s.size();j++){    
            cnt=0;
           if(s[i]==s[j]){
               int gap = j-i;
               for(int k=j;k<s.size();k++){
                   if(s[k-gap]==s[k]){
                       cnt++;
                       ans = max(cnt,ans);
                   }else{
                       
                       break;
                   }
               }
           }
        }
    }

    cout<<ans;
}