#include <iostream>
#include <cmath>
using namespace std;

int s, N, K, R1, R2, C1, C2;

bool isWhite(int len, int y,int x){
    if (len == 1) return 0;
	int nn = len / N;
    
    int pos1 = nn * (N - K)/2;
    int pos2 =  nn * (N + K)/2; 
	if (x >=  pos1 && x < pos2   && y >= pos1 && y < pos2) {
		return 1;
	}
	return isWhite(nn, y % nn, x % nn);
}

int main() {


    cin>>s>> N>> K>> R1>> R2>> C1>> C2;

    if(s==0){
        cout<<"0";
        return 0;
    }


    int side_size =1;
    
    while(s--){
        side_size*=N;
    }

    //범위에 있는 것만 출력

    for(int i=R1;i<=R2;i++){
        for(int j=C1;j<=C2;j++){
            cout<<isWhite(side_size,i,j);
        }
        cout<<endl;
    }
    
    return 0;
}