#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int player[101][101]; //이김 : 1, 짐 -1 , 모름 0
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    //초기 상태
    for(auto r : results){
        player[r[0]][r[1]]=1;
        player[r[1]][r[0]]=-1;
    }
    //계산
    int a=2;
    while(a--){
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || player[i][j])
                    continue;
                for(int k=1;k<=n;k++){
                    if(player[i][k]==1 && player[k][j]==1)
                        player[i][j]=1;
                    else if(player[i][k]==-1 && player[k][j]==-1)
                        player[i][j]=-1;
                }

            }
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout<<player[i][j]<<" ";
    //     cout<<" "<<endl;
    // }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
            if(player[i][j]==0)
                cnt++;
        }
        if(cnt==1)
            answer++;
    }
    
    return answer;
}