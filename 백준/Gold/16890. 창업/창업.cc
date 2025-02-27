#include <iostream>
#include <algorithm>
using namespace std;

//4:02
string s1,s2;
string ans;
int idx=0;
bool turn = true;
int one_idx=0;
int two_idx=0;

//구사과: 만약 다음 사람이 놓을 문자가 내가 놓을 문자랑 같거나 높다면 제일 앞자리에 둘 이유가 없음
//큐브러버: 만약 다음 사람이 놓을 숫자가 내가 놓을 문자보다 같거나 낮다면 내가 앞자리에 둘 이유가 없음. 그 사람이 앞자리에 두는게 이득이니까.


//뒤에서부터 채우기
void fill_ans(string s1,string s2,int s1_idx,int s2_idx){

    //더 마지막에 두는 사람이 
    int ans_back_idx=s1.size();

    int cnt=0;
    for(int i=s1.size()-1;i>=0;i--){
        if(ans[i]=='?')
            cnt++;
    }
    
    int s1_cnt = cnt/2 + cnt%2;
    int s2_cnt = cnt/2;
    
    s1_idx = s1_idx+s1_cnt-1;
    s2_idx = s2_idx + s2_cnt-1;
    
    for(int i= s1.size()-1;i>=0;i-=2){
        if(ans[i]!='?')
            break;
        ans[i] = s1[s1_idx--];
        if(i-1< 0 || ans[i-1]!='?')
            break;
        ans[i-1] = s2[s2_idx--];
    }
}
int main() {
    cin>>s1;
    cin>>s2;
    ans.resize(s1.size());
    
    vector<bool>visited(s1.size());

    
    fill(ans.begin(),ans.end(),'?');
    
    sort(s1.begin(),s1.end());
    sort(s2.rbegin(),s2.rend());
    
    int name_size = s1.size();
    
    int ans_idx=0;
    while(name_size--){
        if(turn){
            if(s1[one_idx]<s2[two_idx]){
                ans[ans_idx++] = s1[one_idx];
                one_idx++;
            }else{

                fill_ans(s1,s2,one_idx,two_idx);
                break;
            }
            turn = false;
        }else{
            if(s1[one_idx]<s2[two_idx]){
                ans[ans_idx++] = s2[two_idx];
                two_idx++;
            }else{
                fill_ans(s2,s1,two_idx,one_idx);
                break;
            }

            turn = true;
        }
    }
    cout<<ans;
    return 0;
}