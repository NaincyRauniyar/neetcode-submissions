class Solution {
public:
bool dfs(vector<vector<char>> & board,string word,int r,int c,int i){
     int n =board.size();
        int m = board[0].size();

    if(i==word.size()) return true;
    if(r<0 ||c<0 || r>=n || c>=m ||
        board[r][c] != word[i] || board[r][c] == '#')
        return false;

        board[r][c] ='#';
        bool res = dfs(board,word,r+1,c,i+1) ||
                    dfs(board,word,r-1,c,i+1) ||
                    dfs(board,word,r,c+1,i+1) ||
                    dfs(board,word,r,c-1,i+1) ;
            board[r][c] = word[i];
            return res;

}
    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0))
                return true;
            }
        }
         return false;
    }
   
};
