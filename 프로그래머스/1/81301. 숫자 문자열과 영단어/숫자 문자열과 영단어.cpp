#include <string>
#include <vector>


using namespace std;



int solution(string s) {
    int answer = 0;
    
    string num_str[]={"zero", "one", "two", "three","four","five","six","seven","eight","nine"};
    for(int i=0;i<10;i++){
        
        while(s.find(num_str[i])!=string::npos){
            s.replace(s.find(num_str[i]),num_str[i].length(),to_string(i));
        }
    }
    answer= stoi(s);
    
    return answer;
}