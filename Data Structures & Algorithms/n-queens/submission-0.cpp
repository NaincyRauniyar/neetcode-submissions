class Solution {
public:
    void solve(int col, vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& l,
               vector<int>& ld,
               vector<int>& ud,
               int n) {

        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {

            if(l[row] == 0 &&
               ld[row + col] == 0 &&
               ud[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';

                l[row] = 1;
                ld[row + col] = 1;
                ud[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, l, ld, ud, n);

                board[row][col] = '.';

                l[row] = 0;
                ld[row + col] = 0;
                ud[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<int> l(n, 0);
        vector<int> ld(2 * n - 1, 0);
        vector<int> ud(2 * n - 1, 0);

        solve(0, board, ans, l, ld, ud, n);

        return ans;
    }
};