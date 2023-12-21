#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int n_size = t*m;
    int i=1;
    int index = p-1;
    int length = 1;
    if(p==1)
    {   answer+='0';
        t--;
        index+=m;
    }
    
    while(t){
        //i를 n진법으로 구하기
        string temp = "";
        int tt = i;
        while(tt){
            temp = string(1,(tt%n)>=10? tt%n + 55 : tt%n + '0') + temp;
            tt=tt/n;
            
        }
        length += temp.size();
         // cout<<temp<<endl;
         // cout<<index<<" "<<length<<endl;
        //t구할 수 있으면 구하기 
        while(index<length && t){
            answer+=temp[index-length+temp.size()];
            t--;
            index +=m;
        }
            
        i++;
        }
        
    
    return answer;
}