#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int name_size=0;
string name;

int search(int start_cursor,int f_ans){
    vector<bool>chk;
    chk.resize(name_size);
    int answer = f_ans;
    int com_cnt=0;
    int cursor = start_cursor;
    
      for(int i=0;i<name_size;i++){
        if(name[i]=='A'){
            chk[i]=true;        
            com_cnt++;
        }
    }
    
    while(com_cnt!=name_size){
         //알파벳 맛춤
        
        if(!chk[cursor])
        {    answer+= name[cursor] - 'A'<'Z' - name[cursor] +1? name[cursor] - 'A' :'Z' - name[cursor]+1;
         com_cnt++;
        }
       // cout<<"a  "<<name[cursor] - 'A'<<"  b  "<<'Z'-name[cursor]+1 <<endl;
        chk[cursor]=true;
        
       // cout<<"answer : "<<answer<<endl;
        //양 옆으로 체크해서 더 가까운쪽으로 이동
        if(com_cnt==name_size)
            break;
        //오른쪽으로 체크
        int right_move = 0,left_move=0;
        int right_cnt=0;
        for(int i=cursor ;right_cnt<=name_size;i++){
            if(!chk[i]){
                right_move=i;
                break;
            }
            right_cnt++;
            if(i==name_size-1)
                i=-1;
        }
        //왼쪽으로 체크
        int left_cnt =0;
        for(int i=cursor ;left_cnt<=name_size;i--){
            if(!chk[i]){
                left_move=i;
                break;                
            }
            left_cnt++;
            if(i==0)
                i=name_size;
        }
      //  cout<<right_cnt<<"  "<<left_cnt<<endl;
        if(right_cnt<left_cnt)
        {  
            cursor=right_move;
            answer+=right_cnt;
        }
        else
        {   
            cursor=left_move;
            answer+=left_cnt;
        }
      //  cout<<"ans2 : "<<answer<<endl;
        
    }
    return answer;
}
int solution(string name2) {
    int ans=0;
    int result1=0;
    int result2=0;
   name_size= name2.size();
   name=name2;
    
  
   
   //  result1 = search(0,0);
   //  result2=search(name_size-1,1);
   // if(result2<result1)
   //     ans= result2;
   //  else
   //      ans=result1;
    ans=search(0,0);
    for(int i=0;i<name_size;i++){
        ans = min(ans,search(i,min(i,name_size-i))); 
    }
    
    return ans;
}