class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<int,int> mpp;
        for(auto i=0;i<n;i++){
            mpp[s[i]] =i;
        }
        vector<int> ans;
        int len=0;
        int end =0 ;
        for(int i=0;i<n;i++){
            len++;
            end = max(end,mpp[s[i]]);

            if(i==end){
                ans.push_back(len);
                len=0;
            }
        }
        return ans;
    }
};
