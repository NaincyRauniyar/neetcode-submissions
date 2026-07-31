class Solution {
public:
bool f(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
   int n = nums.size();
    if(target == 0) return true;
    if(i == n) return false;
    if(dp[i][target] != -1) return dp[i][target];
    bool not_take = f(i+1,target,nums,dp);
    bool take =false;
    if(nums[i] <= target)
    take = f(i+1,target - nums[i],nums,dp);
    return dp[i][target] = take|| not_take;

}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
    
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target = sum/2;
            vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        return f(0,target,nums,dp);
    }
};
