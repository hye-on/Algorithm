#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;
static const int MAXN = 1000000;

// 전역 배열로 미리 선언(문제 크기에 맞게)
long long pow2[MAXN+1]; 
int arrPos[MAXN+1];  // arr[i]: i번째 디스크가 최종적으로 위치할 기둥 번호

int main(){
    ios::sync_with_stdio(false);
 
    int N, K;
    cin >> N >> K;  // N: 디스크 개수, K: 모든 디스크가 모여있는 시작 기둥

    for(int i=1; i<=N; i++){
        cin >> arrPos[i];
    }

    // 1) 2의 거듭제곱 미리 계산
    pow2[0] = 1;
    for(int i=1; i<=N; i++){
        pow2[i] = (pow2[i-1] << 1) % MOD;
    }

    long long answer = 0;
    int curStart = K; // K에서 시작

    // 디스크 n부터 1까지
    for(int i = N; i >= 1; i--){
        if(arrPos[i] == curStart)
            continue;
        // 디스크 i가 움직이기
        // 이동 횟수 += 2^(i-1)
        answer = (answer + pow2[i-1]) % MOD;
       
        //거쳐가는 기둥에서 다시 시작
        curStart= 6 - (curStart + arrPos[i]); 
        
    }

    cout << answer % MOD;
    return 0;
}
