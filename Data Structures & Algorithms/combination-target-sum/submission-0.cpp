class Solution {
public:
void solve(int ind,int target,vector<int>& nums,vector<vector<int>>&ans,vector<int>&ds){
    if(ind == nums.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return ;
    }
    //take 
    if(nums[ind]<=target){
        ds.push_back(nums[ind]);
        solve(ind,target -nums[ind],nums,ans,ds);
        ds.pop_back();
    }
    solve(ind+1,target,nums,ans,ds);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int>ds;
       vector<vector<int>> ans;
       solve(0,target,nums,ans,ds);
       return ans; 
    }
};
