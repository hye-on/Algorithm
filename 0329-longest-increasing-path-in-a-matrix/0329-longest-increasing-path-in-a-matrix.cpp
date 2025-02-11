class Solution {
    
    int dfs(int r,int c ,vector<vector<int>>& matrix,vector<vector<int>>& dp,int n, int m,int prev){

        if(r<0 || r>=n || c<0 || c>=m || prev>=matrix[r][c]) return 0;

        if(dp[r][c]!=-1) 
            return dp[r][c];

        int ans=1;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nr = r+dy[i];
            int nc = c+dx[i];
            ans = max(ans,dfs(nr,nc,matrix,dp,n,m,matrix[r][c])+1);
        }
        dp[r][c] = ans;
        return  dp[r][c];
    }

public:
//백준에 비슷한 문제 있음 bfs+ 메모리 제이션 
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     
        int n = matrix.size();
        int m = matrix[0].size();
        int answer=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                answer = max(answer,dfs(i,j,matrix, dp,n,m,-1));             
            }
        }
        
        return answer;
    }

};