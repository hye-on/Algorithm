#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0 ; i<commands.size(); i++){
        vector<int>temp;
        if(commands[i][0]==commands[i][1])
        {
            answer.push_back(array[commands[i][0]-1]);
            continue;
        }
     temp.assign(array.begin() + commands[i][0]-1,array.end()  - (array.size()-commands[i][1]));  
     sort(temp.begin(),temp.end());
   
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}