class Solution {
public:
int dfs(int i, int j,vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    if(i<0 || j<0 ||i>=n || j>=m|| grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    return 1+ dfs(i,j-1,grid)
            +dfs(i-1,j,grid)
            +dfs(i+1,j,grid)
            +dfs(i,j+1,grid);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
         int m = grid[0].size();
         int maxi =0;

         for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi,dfs(i,j,grid));
                }
            }
         }
         return maxi;
    }
};
