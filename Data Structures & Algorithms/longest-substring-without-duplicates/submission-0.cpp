class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n =s.size();
      int ans=0;
      for(int i=0;i<n;i++){
        unordered_set<char> c;
        for(int j=i;j<n;j++){
            if(c.find(s[j]) != c.end()){
                break;
            }
            c.insert(s[j]);
        }
        ans = max(ans, (int)c.size());
      }
      return ans;
    }
};
