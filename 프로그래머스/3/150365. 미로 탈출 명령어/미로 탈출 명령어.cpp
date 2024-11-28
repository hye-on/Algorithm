#include <string>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
   // 각 방향으로의 최소 이동 횟수 계산
   int down = max(0, r-x);
   int left = max(0, y-c);
   int up = max(0, x-r);
   int right = max(0, c-y);
   
   // 최소 이동 거리
   int dist = down + left + up + right;
   if(k < dist || (k - dist) % 2 == 1) return "impossible";
   
   int spare = (k - dist) / 2;  // 여분의 이동 횟수
   string answer = "";
   
   // 1. down 먼저
   for(int i = 0; i < down; i++) 
       answer += 'd';
   
   // 아래로 더 갈 수 있으면 최대한 이동
   int extra_down = 0;
   while(spare > 0 && x + down + extra_down + 1 <= n) {
       answer += 'd';
       extra_down++;
       spare--;
   }
   
   // 2. left 처리
   for(int i = 0; i < left; i++) 
       answer += 'l';
       
   // 왼쪽으로 더 갈 수 있으면 최대한 이동
   int extra_left = 0;
   while(spare > 0 && y - left - extra_left - 1 >= 1) {
       answer += 'l';
       extra_left++;
       spare--;
   }
   
   // 3. spare가 남았다면 rl 반복으로 소진
   while(spare > 0) {
       answer += "rl";
       spare--;
   }
   
   // 4. right 처리 (extra_left만큼 더 이동)
   for(int i = 0; i < right + extra_left; i++) 
       answer += 'r';
   
   // 5. up 처리 (extra_down만큼 더 이동)
   for(int i = 0; i < up + extra_down; i++) 
       answer += 'u';
   
   return answer;
}