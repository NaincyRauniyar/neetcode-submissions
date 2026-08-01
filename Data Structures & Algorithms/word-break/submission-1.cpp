class Solution {
public:
bool f(int i,string &s, vector<string>& wordDict,vector<int>&dp){
    int n = s.size();
    if(i==n) return true;
    if(dp[i] != -1) return dp[i];

    for(int c=i;c<n;c++){
        string sub = s.substr(i,c-i+1);
        for(auto st: wordDict){
            if(sub == st && f(c+1,s,wordDict,dp))
            return dp[i] = true;
        }
    }
    return dp[i] = false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,s,wordDict,dp);
    }
};
