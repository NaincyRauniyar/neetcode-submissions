class Solution {
public:
vector<int> dr ={-1,0,1,0};
vector<int>dc = {0,1,0,-1};
void dfs(int i,int j,vector<vector<char>>&b, vector<vector<int>> &vis){
    int n = b.size();
    int m = b[0].size();

    vis[i][j] = 1;
    for(int l=0;l<4;l++){
        int nr = i+dr[l];
        int nc= j+dc[l];
        if(nr>=0 && nc >=0 && nr<n&& nc < m&& !vis[nr][nc] && b[nr][nc] == 'O' )
        dfs(nr,nc,b,vis);
    }
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
       for(int j=0;j<m;j++){
    if(!vis[0][j] && board[0][j] =='O')
        dfs(0,j,board,vis);

    if(!vis[n-1][j] && board[n-1][j] =='O')
        dfs(n-1,j,board,vis);
}

for(int i=0;i<n;i++){
    if(!vis[i][0] && board[i][0] == 'O')
        dfs(i,0,board,vis);

    if(!vis[i][m-1] && board[i][m-1] =='O')
        dfs(i,m-1,board,vis);
}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O')
                board[i][j] ='X';
            }
        }
        return ;
    }
};
