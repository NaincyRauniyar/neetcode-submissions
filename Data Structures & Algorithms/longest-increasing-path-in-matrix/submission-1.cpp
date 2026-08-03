class Solution {
public:
vector<vector<int>> dir =  {{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int r,int c,int prev,vector<vector<int>>& matrix,vector<vector<int>>&dp){
    int row = matrix.size();
    int col = matrix[0].size();

    if(r<0||c<0 || r>=row || c>=col || matrix[r][c] <=prev) return 0;
    if(dp[r][c] != -1) return dp[r][c];

    int res=1;
    for(auto d: dir){
        res = max(res,1+ dfs(r+d[0],c+d[1],matrix[r][c],matrix,dp));
    }
    return  dp[r][c] = res;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         int row = matrix.size();
    int col = matrix[0].size();
    int ans =0;

    vector<vector<int>>dp(row+1,vector<int>(col+1,-1));

    for(int r=0;r<row;r++){
        for(int c =0;c<col;c++){
            ans = max(ans,dfs(r,c,-1,matrix,dp));
        }
    }
      return ans;
    }
};