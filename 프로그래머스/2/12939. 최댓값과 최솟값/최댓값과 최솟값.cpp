#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int maxN=-1000000000,minN=1000000000;
    string tmp="";
    int t=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ')
            tmp+=s[i];
        if(s[i]==' '|| (i==s.size()-1)){
            t = stoi(tmp);
            if(t>maxN)
                maxN=t;
            if(t<minN)
                minN=t;
            tmp="";
            
        }
    }
    answer = to_string(minN)+" "+to_string(maxN);
    return answer;
}