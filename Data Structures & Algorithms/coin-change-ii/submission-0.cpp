class Solution {
public:
int f(int ind,int amt, vector<int>& coins,vector<vector<int>>&dp){
    if(ind == 0) return (amt %coins[0] == 0);
    if(dp[ind][amt] != -1) return dp[ind][amt];

    int nt = 0+ f(ind-1,amt,coins,dp);
    int t =0;
    if(amt >= coins[ind])
    t = f(ind,amt - coins[ind],coins,dp);
    return dp[ind][amt] =  t+nt;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};
