class Solution {
public:
    string minWindow(string s, string t) {
      vector<int> hash(128,0);
      int n =s.length();
      int m = t.length();

      for(auto x: t){
        hash[x]++;
      }  
      int cnt = m;
      int l=0,r=0,mini =INT_MAX,ind=-1;

      while(r<n){
        if(hash[s[r]]>0)
        cnt--;
        
        hash[s[r]]--;
        r++;

        while(cnt==0){
            if(r-l<mini){
                mini = r-l;
                ind =l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)cnt++;
            l++;
        }
      }
      return mini == INT_MAX?"":s.substr(ind,mini);
    }
};