// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
//9:31
int n,m;
vector<int>parent;

int findParent(int a){
    if(parent[a]==a)
        return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b){
    int aP = findParent(a);
    int bP = findParent(b);
    
    if(aP<bP)
        parent[bP] = aP;
    else
        parent[aP] = bP; 
}
int main() {
    ios_base :: sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    
    cin>>n>>m;
    parent.resize(n+1);
    int a=0,b=0,c=0;
    for(int i=0;i<=n;i++)
        parent[i]=i;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a==0)
            unionParent(b,c);
        else{
            int bP = findParent(b);
            int cP = findParent(c);
            if(bP==cP)
                cout<<"yes"<<"\n";
            else
                cout<<"no"<<"\n";
        }
            
    }

    return 0;
}