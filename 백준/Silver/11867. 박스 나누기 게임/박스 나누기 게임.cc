#include <iostream>
#include <vector>


using namespace std;

int n,m;

int main() {
    
    cin>>n>>m;

    if(n%2==0 || m%2==0)
        cout<<'A';
    else
        cout<<'B';
   
    return 0;
}