class Solution {
public:
    // int f(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {

    //     if (amt == 0) return 0;
    //     if (i < 0) return 1e9;

    //     if (dp[i][amt] != -1) return dp[i][amt];

    //     int nottake = f(i - 1, amt, coins, dp);

    //     int take = 1e9;
    //     if (amt >= coins[i]) {
    //         take = 1 + f(i, amt - coins[i], coins, dp);
    //     }

    //     return dp[i][amt] = min(take, nottake);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

       for(int i=0;i<n;i++){
        dp[i][0] =0 ;
       }
       for(int amt =0;amt<=amount;amt++){
        if(amt%coins[0] == 0)
        dp[0][amt] = amt/coins[0];
       }
       for(int i=1;i<n;i++){
        for(int amt=0;amt<=amount;amt++){
              int nottake = dp[i-1][amt];

        int take = 1e9;
        if (amt >= coins[i]) {
            take = 1 +dp[i][amt - coins[i]];
        }
        dp[i][amt ] = min(take,nottake);
        }
       }
       int ans  = dp[n-1][amount];
       if(ans >= 1e9) return -1;
       return ans;
    }
};