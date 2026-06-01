class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int ans=0;
        int l=0;
        int maxi=0;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            maxi = max(maxi,mpp[s[r]]);

            while((r-l+1) - maxi >k){
                mpp[s[l]]--;l++;
            }
            ans = max(ans,r-l+1);
        }
    return ans;
    }
};
