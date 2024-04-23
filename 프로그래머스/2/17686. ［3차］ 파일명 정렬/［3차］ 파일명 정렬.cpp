#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool compare(string a , string b){
    int idxA =0, idxB=0;
    //Head 비교 : 한쪽이 더 길면 어차피 문자가 더 크다. 즉 앞으로 감
    
      
        string tmpA="",tmpB="";
        while('0'>a[idxA] || a[idxA]>'9')
        {  
            tmpA+=tolower(a[idxA]);
            idxA++;
        }
        while('0'>b[idxB] || b[idxB]>'9')
        {     tmpB+=tolower(b[idxB]);   
                idxB++;
        }      
        if(tmpA<tmpB)
            return true;
        else if(tmpA>tmpB)
            return false;
    
    
  
    //둘 다 숫자가 나오면 0나오기 전까지 인덱스 미루고 숫자로 바꿔서 비교
    //cout<<a<<" "<<b<<endl;
    string aN ="",bN="";
    while(idxA<a.size() && a[idxA]!='.'){
        aN+=a[idxA];
        idxA++;
    }
    
    while(idxB<b.size() && b[idxB]!='.'){
        bN+=b[idxB];
        idxB++;
    }
    int aa = stoi(aN);
    int bb = stoi(bN);
   // cout<<aa<<" "<<bb<<endl;
    //cout<<"===="<<endl;
    if(aa<bb)
        return true;
    else if(aa>bb)
        return false;
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    int size= files.size();
    
   // cout<< "  "<<'-'+'A'<<"  "<< 'A'+'A';
   stable_sort(files.begin(),files.end(),compare);
   
    answer= files;
    return answer;
}