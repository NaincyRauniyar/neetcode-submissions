class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto &x: nums){
            mpp[x]++;
        }
        vector<int> ans;
        vector<pair<int, int>> arr;
        for(auto &[a,b] :mpp){
            arr.push_back({b,a});
        }
        sort(arr.rbegin(),arr.rend());
        for(int i =0;i<k;i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
