//스택
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;  
        int ans = 0;
        int n = height.size();
        
        for (int i = 0; i < n; i++) {
            int h = height[i];
            // 현재 높이가 스택의 top에 있는 높이보다 크면
            // 그 사이에 물이 고일 수 있음
            while (!st.empty() &&  height[st.top()]<h) {
                int top = st.top();
                st.pop();
                
                //벽이 없으면 고일 수 없음
                if (st.empty()) {
                    break;  
                }
                
              
                int w = i - st.top() - 1;
               
                //height[top] 이하인 부분에는 이미 다 계산 했으므로
                int wh = min(height[i], height[st.top()]) - height[top];
                
                ans += w * wh;
            }
            st.push(i);  
        }
        
        return ans;
    }
    
};