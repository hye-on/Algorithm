#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
//개수를 저장해야 하는 union-find
//12:15
int t,n;
string a,b;
map<string,string>parent;
map<string,string>parent_t;
map<string,int>headcount;
map<string,int>headcount_t;
string findParent(string f){
    if(parent.find(f)!=parent.end() && f==parent[f])
        return parent[f];

    return parent[f] = findParent(parent[f]);
}

void unionParent(string a, string b){
    a = findParent(a);
    b = findParent(b);
    if(a.size()>b.size()){
        
        parent[a] = b;
        headcount[a] += headcount[b];
        headcount[b] = headcount[a];
    }
    else{
       
        parent[b] = a;
        headcount[b] += headcount[a];
        headcount[a] = headcount[b]; 
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    
    while(t--){
        cin>>n;
      
        map<string,bool>name;
        parent = parent_t;
        headcount = headcount_t;
        
        
        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(parent.find(a)==parent.end()){
                parent[a] =a;
                headcount[a]++;
            }
            if(parent.find(b)==parent.end()){
                parent[b] =b;
                headcount[b]++;
            }
            if(findParent(a)!=findParent(b)){
                unionParent(a,b);
            }         

            cout<<headcount[findParent(a)]<<'\n';
        }
    }
    return 0;
}