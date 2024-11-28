#include <string>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    // 각 방향으로 가야하는 최소 횟수 계산
    int down = max(0, r-x);
    int left = max(0, y-c);
    int up = max(0, x-r);
    int right = max(0, c-y);
    
    // 불가능한 경우 체크
    int minDist = down + left + up + right;
    if(k < minDist || (k - minDist) % 2 == 1) 
        return "impossible";
        
    // 상쇄 이동 횟수
    int pair = (k - minDist) / 2;
    int curX = x, curY = y;
    string answer = "";
    
    for(int i = 0; i < k; i++) {
        // down (아래로 갈 수 있고, 필수 이동이 남았거나 상쇄 이동이 가능할 때)
        if(curX < n && (down > 0 || pair > 0)) {
            answer += 'd';
            curX++;
            if(down > 0) down--;
            else {
                pair--;
                up++;
            }
        }
        // left
        else if(curY > 1 && (left > 0 || pair > 0)) {
            answer += 'l';
            curY--;
            if(left > 0) left--;
            else {
                pair--;
                right++;
            }
        }
        // right
        else if(curY < m && (right > 0 || pair > 0)) {
            answer += 'r';
            curY++;
            if(right > 0) right--;
            else {
                pair--;
                left++;
            }
        }
        // up
        else if(curX > 1 && (up > 0 || pair > 0)) {
            answer += 'u';
            curX--;
            if(up > 0) up--;
            else {
                pair--;
                down++;
            }
        }
    }
    
    return answer;
}