#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;
// 핵심은 점프 -> kmp
// 다음 비교할 부분을 접미사랑 미리 맞춰두기- 점프해서

vector<int> getPi(string p){
    int m = p.size();
    int prefix_i = 0;
    vector<int> pi(m,0);

    for(int suffix_i =1; suffix_i<m; suffix_i++){

        //일차하지 않는 것이 있으면 미리 구해놨던 접미사와 접두사를 이용해 앞에 부분 일치 시켜놓음
        // ABABABA C
        //   ABABA B  
        // === 점프
        // ABABABA C       -> ABABABA -> 접두사, 접미사 -> ABA
        //     ABABA B  
        //일치 할 때까지 점프해서 while

        while(prefix_i>0 && p[suffix_i]  != p[prefix_i]){
            prefix_i = pi[prefix_i-1];
        }
        if(p[suffix_i]==p[prefix_i])
            pi[suffix_i] =  ++prefix_i;
    }

    return pi;
}

vector<int>kmp(string s, string p){
    vector<int>ans;
    vector<int> pi = getPi(p); // 접두사와 접미사 일치 길이
    int n = s.size();
    int m =p.size();
    int prefix_i=0;

    for(int suffix_i=0;suffix_i<n;suffix_i++){
        while(prefix_i>0 && s[suffix_i]!=p[prefix_i])
            prefix_i = pi[prefix_i-1];

        if(s[suffix_i]==p[prefix_i]){
            if(prefix_i==m-1){ //문자열 끝까지 일치하면
                ans.push_back(suffix_i-m+1);
                prefix_i = pi[prefix_i];
            }else{
                prefix_i++;
            }
        }
    }
    return ans;
}

int main() {
    string s,p;
    getline(cin,s);
    getline(cin,p);

    vector<int> matched = kmp(s,p);
    cout<< matched.size()<<'\n';
    for(auto i : matched)
        cout<<i+1<<'\n';
    return 0;
}