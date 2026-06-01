class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_map<int,int> mpp;
      for(auto x:nums){
        mpp[x]++;
      }  
      for(auto &[a,b]: mpp){
        if(b>1){
            return true;
        }
      }
      return false;
    }
};