class Solution {
public:
vector<int>dr = {-1,0,1,0};
vector<int>dc = {0,1,0,-1};
void dfs(int r,int c, vector<vector<int>> &h,vector<vector<int>>&vis){
    int n = h.size();
    int m = h[0].size();
    vis[r][c] =1;
    for(int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && h[nr][nc]>=h[r][c])
        dfs(nr,nc,h,vis);
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atl(n,vector<int>(m,0));

        //top and bottom
        for(int j=0;j<m;j++){
            if(!pac[0][j])
            dfs(0,j,heights,pac);
            if(!atl[n-1][j])
            dfs(n-1,j,heights,atl);
        }
        //leftand right
        for(int i=0;i<n;i++){
            if(!pac[i][0])
            dfs(i,0,heights,pac);
            if(!atl[i][m-1])
            dfs(i,m-1,heights,atl);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};