class Solution {
public:

void solve(int ind,int target,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
    if(target == 0){
        ans.push_back(ds);
        return ;
    }
    for(int i=ind;i<nums.size();i++){
        if(i>ind && nums[i] == nums[i-1]) continue;
        if(nums[i]>target) break;

        ds.push_back(nums[i]);
        solve(i+1,target-nums[i],nums,ans,ds);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<int>ds;
        vector<vector<int>> ans;
        solve(0,target,candidates,ans,ds);
        return ans;
    }
};
