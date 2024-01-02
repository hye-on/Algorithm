#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int>player;
    int size=participant.size();
    for(int i=0;i<size;i++)
        player[participant[i]]++;
    for(int i=0;i<size-1;i++)
    {
        if(player.find(completion[i])->second>1)
            player[completion[i]]--;
        else
            player.erase(completion[i]);
    }
   answer = player.begin()->first;
    return answer;
}