class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int x: nums){
            int str =0 ,cur= x;
            while(s.find(cur) != s.end()){
            str++;cur++;}
            ans = max(ans,str);
        }
return ans;
    }
};
