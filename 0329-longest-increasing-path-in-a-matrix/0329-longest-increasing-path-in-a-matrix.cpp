class Solution {
public:
//백준에 비슷한 문제 있음 bfs+ 메모리 제이션 
    int answer=0;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      //  matrix = {{1,4,7,9},{0,3,8,5},{3,6,0,6},{1,4,5,6}};
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        fill(dp.begin(),dp.end(),vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==0)
                    bfs(i,j,dp,n,m,matrix);
               
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               answer = max(answer,dp[i][j]);
             //   cout<<dp[i][j]<<' ';
            }
          //  cout<<endl;
        }
        return answer;
    }




    void bfs(int sy,int sx,vector<vector<int>>&dp, int& n,int& m,vector<vector<int>>& matrix){
        int dy[] ={0,1,0,-1};
        int dx[] = {1,0,-1,0};
        queue<pair<pair<int,int>,int>>q;

        q.push({{sy,sx},1});
        dp[sy][sx]=1;

        while(!q.empty()){
            int cury = q.front().first.first;
            int curx = q.front().first.second;
            int d = q.front().second;
            q.pop();
           
            for(int i=0;i<4;i++){
                int ny = cury + dy[i];
                int nx = curx + dx[i];

                if(ny>=n || ny<0 || nx>=m || nx<0)
                    continue;
                if(matrix[ny][nx]<=matrix[cury][curx])
                    continue;
               if(dp[ny][nx] < d+1){
                dp[ny][nx] = d+1;
                q.push({{ny,nx},d+1});
                }
            }
        }
    }
};