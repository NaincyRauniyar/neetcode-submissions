class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> ans;
        for(auto &x : strs){
            auto key = x;
            sort(key.begin(),key.end());
            mpp[key].push_back(x);
        }
        for(auto &p : mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
