#include <string>
#include <vector>
#include <iostream>
using namespace std;


string solution(string number, int k) {
    string answer = "";
    for(int i=0;i<number.size()-1;i++){
        if(k==0)
            break;
        if(number[i]<number[i+1]){
            k--;
            number.erase(i,1);
             i=-1;
            
        }
        
    }
    
    if(k>0){
        number.erase(number.size()-k,k);
    }
    return answer=number;
}