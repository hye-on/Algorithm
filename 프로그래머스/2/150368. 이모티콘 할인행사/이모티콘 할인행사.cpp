#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num[] = {60,70,80,90};
vector<int> n;
int emoticons_size;
vector<vector<int>> users_c;
vector<int> emoticons_c;
int join_max,money_max;
void calculate(){

    int join=0,money=0;
    for(auto u : users_c){
        int sum=0;   
        for(int j=0;j<emoticons_size;j++){
            if(sum >= u[1])
            {   
                break;;
            }
            if(u[0] <=100-n[j] )
            {  
                sum+=(n[j]*emoticons_c[j]/100);
               
            }
            
          
        }
        
         if(sum>= u[1])
        {
                join++;
                sum=0;
                
               
        }else{
             money+=sum;
         }
        
    }

    if(join>=join_max){
       // cout<<join<< " "<<money<<endl;
        if( join!=join_max)
            money_max=0;
        
        money_max = max(money_max,money);
        join_max=join;

    }


    
}
void dfs (int index){
    if(index==emoticons_size){
        calculate();
        
        return;
    }
    for(int i=0;i<4;i++){
        n[index] = num[i];
        dfs(index+1);
        
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    users_c.assign(users.begin(),users.end());
    emoticons_c.assign(emoticons.begin(),emoticons.end());
    emoticons_size=emoticons.size();
    
    n.resize(emoticons_size);
    dfs(0);
    answer.push_back(join_max);
    answer.push_back(money_max);
    return answer;
}