class Solution {
public:
    int f(int i, int amt, vector<int>& coins, vector<vector<int>>& dp) {

        if (amt == 0) return 0;
        if (i < 0) return 1e9;

        if (dp[i][amt] != -1) return dp[i][amt];

        int nottake = f(i - 1, amt, coins, dp);

        int take = 1e9;
        if (amt >= coins[i]) {
            take = 1 + f(i, amt - coins[i], coins, dp);
        }

        return dp[i][amt] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};