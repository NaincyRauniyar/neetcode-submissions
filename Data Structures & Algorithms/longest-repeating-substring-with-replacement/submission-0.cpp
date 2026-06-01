class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
       int res=0;
       for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        int maxi =0;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            maxi = max(maxi,mpp[s[j]]);
            if((j-i+1) -maxi <=k){
                res = max(res,j-i+1);
            }
        }
       } 
       return res;
    }
};
