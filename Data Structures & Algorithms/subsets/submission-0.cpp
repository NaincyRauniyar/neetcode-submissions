class Solution {
public:
void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
    ans.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        ds.push_back(nums[i]);
        solve(i+1,nums,ans,ds);
        ds.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>s;
        vector<vector<int>> ans;
        solve(0,nums,ans,s);
        return ans;
    }
};
