int n;
set<long long>s;
long long t;
long long ans;
class Solution {
public:
    int nthUglyNumber(int n) {
        for(int i=0;i<=30;i++){
             long long pow2 = (1LL << i);  // 2의 i승
                for(int j=0;j<=19;j++){
                     long long pow3 = pow(3, j);  // 3의 j승
                       if (pow2 > LLONG_MAX / pow3) break;  // long long 범위 초과 방지
                    for(int k=0;k<=13;k++){
                         long long pow5 = pow(5, k);  // 5의 k승

                    if (pow2 * pow3 > LLONG_MAX / pow5) break;  // long long 범위 초과 방지

                    t = pow2 * pow3 * pow5;  // 최종 못생긴 수 계산
                    s.insert(t);  // set에 삽입하여 중복 제거
                    }
                }
            }
            int idx=0;
        
            for(auto it = s.begin();it!=s.end();it++){
                idx++;
                if(idx==n){
                    ans = *it;
                   break;
                }
            }
            return ans;   
    }

};