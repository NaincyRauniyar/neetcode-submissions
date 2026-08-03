class Solution {
public:
int f(int i,int total,vector<int>& nums, int target,vector<vector<int>>&dp,int totalsum){
    int n = nums.size();
    if(i==n) return  total == target;
    if(dp[i][total+totalsum] != -1) return dp[i][total+totalsum];

    int add = f(i+1,total+nums[i],nums,target,dp,totalsum);
    int sub = f(i+1,total-nums[i],nums,target,dp,totalsum);

    return dp[i][total+totalsum]= add+sub;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*totalsum+1,-1));
        return f(0,0,nums,target,dp,totalsum);
    }
};
