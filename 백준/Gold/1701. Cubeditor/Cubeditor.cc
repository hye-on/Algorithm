#include <iostream>

using namespace std;
//5000*5000*5000-> 75000000000
//투포인터로 하고 최적화
string s;

int main() {
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size()-ans;j++){
            if(s[i]==s[j]){
                int cnt=0;
                for(int k=0;j+k<s.size();k++){
                    if(s[i+k]==s[j+k]){
                        cnt++;
                    }else{
                        break;
                    }
                }
                ans = max(ans,cnt);
            }
        }
    }
    cout<<ans;
    return 0;
}