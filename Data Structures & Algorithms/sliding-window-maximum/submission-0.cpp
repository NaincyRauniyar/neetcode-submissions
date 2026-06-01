class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0 , j = k-1;
        vector<int> ans;
        while(j<n){
            int maxi = nums[l];
            for(int i=l;i<=j;i++){
                maxi = max(maxi, nums[i]);
            }
                ans.push_back(maxi);
            l++;
            j++;
        }
        return ans;
    }
};
